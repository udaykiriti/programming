import numpy as np
import mpmath
import re
mpmath.mp.dps = 50

def lgamma_hp(x):
    return float(mpmath.loggamma(mpmath.mpf(x)))

def to_hex_float(v):
    f32 = float(np.float32(v))
    h = f32.hex()
    m = re.match(r'(-?)0x([01])\.([0-9a-f]+)p([+-]\d+)', h)
    sign, intpart, frac, exp = m.groups()
    frac = frac.rstrip('0') or '0'
    return f"{sign}0x{intpart}.{frac}p{int(exp):+d}f"

def fit_minimax(n):
    center = n + 0.5
    # Chebyshev nodes on [-0.5, 0.5]
    k = np.arange(1, 201)
    ts = -0.5 * np.cos(np.pi * (2*k - 1) / 400)
    ys = np.array([lgamma_hp(t + center) for t in ts])
    coeffs_f32 = np.polyfit(ts, ys, 4)[::-1].astype(np.float32)

    # measure max relative error on dense grid
    xs_check = np.linspace(n + 1e-6, n + 1 - 1e-6, 2000)
    ts_check = xs_check - center
    approx = np.polyval(coeffs_f32[::-1], ts_check)
    exact = np.array([lgamma_hp(x) for x in xs_check])
    mask = np.abs(exact) > 0.01
    rel_err = np.max(np.abs((approx[mask] - exact[mask]) / exact[mask]))

    return coeffs_f32, rel_err

for n in range(1, 8):
    c, err = fit_minimax(n)
    hx = [to_hex_float(v) for v in c]
    print(f"      // [{n},{n+1}), center={n}.5, max_rel_err={err:.2e}")
    print(f"      {{{hx[0]}, {hx[1]}, {hx[2]}, {hx[3]},")
    print(f"       {hx[4]}}},")
