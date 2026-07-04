#!/usr/bin/env python3
"""
LGAMMA_POLY coefficients for lgammabf16.h

Fits a degree-4 polynomial to lgamma(x) on each interval [n, n+1)
for n = 1..7, centered at the midpoint n+0.5. mpmath provides a
high-precision reference; numpy does the least-squares fit.

Note on relative error for [1,2) and [2,3):
  lgamma has zeros at x=1 and x=2, so relative error blows up near
  those points even when absolute error is tiny. We skip points where
  |lgamma(x)| < 0.01 when computing max_rel_err.

Paste the output into the LGAMMA_POLY table inside lgamma_positive_d()
in lgammabf16.h.

used:
    numpy, mpmath
"""

import re
import numpy as np
import mpmath

mpmath.mp.dps = 50  # way more precision than float32 needs


def lgamma_hp(x):
    # mpmath loggamma is our ground truth reference
    return float(mpmath.loggamma(mpmath.mpf(x)))


def to_hex_float(v):
    # cast to float32 first, then format as C hex literal e.g. 0x1.8p+0f
    f32 = float(np.float32(v))
    h = f32.hex()  # Python gives e.g. '0x1.eeb28000000000p-4'
    m = re.match(r'(-?)0x([01])\.([0-9a-f]+)p([+-]\d+)', h)
    sign, intpart, frac, exp = m.groups()
    frac = frac.rstrip('0') or '0'  # strip float64 trailing zeros
    return f"{sign}0x{intpart}.{frac}p{int(exp):+d}f"


def fit_one_interval(n):
    center = n + 0.5
    f = lambda t: mpmath.loggamma(mpmath.mpf(t + center))

    # chebyfit returns descending order [c4, c3, c2, c1, c0]
    # degree=4 means we need n+1=5 coefficients, pass deg=4
    coeffs_mp = mpmath.chebyfit(f, [-0.5, 0.5], 5)  # 5 = number of coeffs = degree+1

    # Reverse to ascending order: c0 + c1*t + c2*t^2 + c3*t^3 + c4*t^4
    coeffs_f32 = np.array([float(c) for c in reversed(coeffs_mp)], dtype=np.float32)

    # Measure max relative error on dense grid using float32 coefficients
    xs_check = np.linspace(n + 1e-6, n + 1 - 1e-6, 2000)
    ts_check = xs_check - center
    approx = np.polyval(coeffs_f32[::-1], ts_check)
    exact   = np.array([lgamma_hp(x) for x in xs_check])

    # Skip near-zero lgamma values (zeros at x=1,2 blow up relative error)
    mask = np.abs(exact) > 0.01
    rel_err = np.max(np.abs((approx[mask] - exact[mask]) / exact[mask]))

    return coeffs_f32, rel_err


def main():
    for n in range(1, 8):
        coeffs, err = fit_one_interval(n)
        c = [to_hex_float(v) for v in coeffs]
        print(f"    // [{n},{n+1}), center={n}.5, max_rel_err={err:.2e}")
        print(f"    {{{c[0]}, {c[1]}, {c[2]}, {c[3]},")
        print(f"     {c[4]}}},")


if __name__ == "__main__":
    main()
