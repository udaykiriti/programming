#ifdef LOCAL
    #undef _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #if __has_include("algo/debug.h")
        #include "algo/debug.h"
    #else
        #define debug(...) ((void)0)
    #endif
#else
    #define debug(...) ((void)0)
#endif

using db = long double;  // or double, if TL is tight
using str = string;      // like python!

/* Complex to expand compared to normal ones, but looks cool.*/
#define tcT template <class T
#define tcTU tcT, class U
#define tcTUV tcT, class U, class V // It doesn't make any Sense
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT > using V1 = V<T>;
tcT > using VV = V<V<T>>;
tcT, size_t SZ > using AR = array<T, SZ>;

#define tcTP template <class... T
#define tcTPU tcTP, class... U

using vi = V<int>;
using vb = V<bool>;
using vl = V<int64_t>;
using vd = V<db>;
using vs = V<str>;

#define FIXED(x) do { cout << fixed << setprecision(x); } while(0)

const int MOD = 998244353;  // 1e9+7;
constexpr int64_t INF = 1e18;
constexpr int64_t EPS = 1e-9;
const int64_t MAX = 1e18;  // not too close to LLONG_MAX
const int MIN = -1e7;

#define endl      '\n'
#define pb        push_back
#define eb        emplace_back
#define all(x)    begin(x), end(x)
#define F         first
#define S         second
#define MIN(x)    *min_element(all(x))
#define MAX(x)    *max_element(all(x))
#define lb        lower_bound
#define ub        upper_bound
tcT > int lwb(const V<T> &a, const T &b) { return int(lb(a.begin(), a.end(), b) - a.begin()); }
tcT > int upb(const V<T> &a, const T &b) { return int(ub(a.begin(), a.end(), b) - a.begin()); }

tcT>
constexpr bool isEven(T x) { return 0 == x % 2; }
tcT >
constexpr bool isOdd(T x) { return 0 != x % 2; }
tcT >
constexpr T uceil(T a, T b) { return (a + b - 1) / b; }

template <class T>
[[nodiscard]] constexpr int sz(const T& c) { return static_cast<int>(std::size(c)); }

// #define ONPC

void _GO() {
    int n;
    cin >> n;
    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    bool chgd{true};

    while(chgd){
        chgd = false;
        for(int i = 0; i < n - 1; i++){
         if((vec[i] ^ vec[i + 1]) < 4 && vec[i] > vec[i + 1]){
           swap(vec[i], vec[i + 1]);
           chgd = true;
         }
       }
    }
    for(int i = 0; i < n; i++){
        cout << vec[i] << " \n"[i == n - 1];
    }
}

int main(/* int argc, char *argv[] */) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin.tie(0)->ios::sync_with_stdio(0);
    #ifdef ONPC
        freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
        cout << "o_o >--< o_o >>>>>>>>>> Compiled <<<<<<<<<< o_o >--< o_o" << '\n';
    #endif
    int t{1},tcase{0}; cin >> t;
    while (tcase++,t--){
        _GO();
    }
    return 0;
}

/* Look for |>
 * Non-trivial problems with simple solutions, proofs, and implementations.
 * check for ub/lb, special cases (n=1?) ,edge cases, bounds,;check them first.
 * Try working from backward or endcases.
 * Do not make large assumptions without a basic proof idea.
 * Use DP to relax constraints; store only the minimum required state.
 * Always careful with Base conditions.
 * Do something instead of nothing; stay organized; Write stuff down.
 * Eliminate Wrong Ideas First; switch to another approach.
 * If you don't get solution within time Just Give Up..
 */
