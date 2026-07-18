#undef _GLIBCXX_DEBUG

/*
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <containers>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

// Old Libraries
// Source - https://stackoverflow.com/a/26803644
// Posted by deW1, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-03, License - CC BY-SA 3.0

// C++ Full Standard Header Include
#include <cstdlib>
#include <csignal>
#include <csetjmp>
#include <cstdarg>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <chrono>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#include <new>
#include <memory>
#include <scoped_allocator>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <limits>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <system_error>
#include <cerrno>
#include <cctype>
#include <cwctype>
#include <cstring>
#include <cwstring>
#include <cwchar>
#include <cuchar>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <valarray>
#include <random>
#include <numeric>
#include <ratio>
#include <cfenv>
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <strstream>
#include <iomanip>
#include <streambuf>
#include <cstdio>
#include <locale>
#include <clocale>
#include <codecvt>
#include <regex>
#include <atomic>
#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <ciso646>
#include <ccomplex>
#include <ctgmath>
#include <cstdalign>
#include <cstdbool>
*/

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#ifdef USE_PBDS
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>

  using namespace __gnu_pbds;

  template <class T>
  using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

  template <class K, class V>
  using ordered_map = tree<K, V, std::less<K>, rb_tree_tag, tree_order_statistics_node_update>;

  template <class T>
  using multiordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

  // optional convenience typedefs:
  using pii = std::pair<int,int>;
#endif


using int_64 = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // like python!

/* Pairs */
using pi = pair <int,int>;
using pll = pair<int_64, int_64>;
using pdb = pair<db,db>;

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
using vl = V<int_64>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pll>;
using vpd = V<pdb>;

#define MaT2D(name, rows, cols) vector<vector<int>> name(rows, vector<int>(cols))
template <typename T>
using Mat = vector<vector<T>>;

template <typename T>
Mat<T> make_mat(int n, int m, T val = T()) {
    return Mat<T>(n, vector<T>(m, val));
}

/*
#define os_insert(s, val) s.insert(val)
#define os_erase(s, val) s.erase(val)
#define os_kth(s, k) *s.find_by_order(k)
#define os_rank(s, val) s.order_of_key(val)
#define os_size(s) ((int)s.size())
#define oms_insert(ms, val) ms.insert({val, timer++})
#define oms_erase(ms, val) ms.erase(ms.lower_bound({val, 0}))
#define oms_kth(ms, k) ms.find_by_order(k)->first
#define oms_rank(ms, val) ms.order_of_key({val, 0})
*/

#define FIXED(x) cout << fixed << setprecision(x) << '\n';

/*
#define debug(x) cout << (x) << '\n'
#define debugVec(v) do { cout << #v << " = "; for (auto u : v) cout << u << " "; cout << endl; } while(0)
#define printm(m) do { cout << "[\n"; for (auto i : m) cout << i.first << " -> " << i.second << '\n' ; cout << "...]\n"; } while(0)
#define prints(s) do { cout << "{"; for (auto i : s) cout << i << ' '; cout << "}\n"; } while(0)
*/

const int MOD = 998244353;  // 1e9+7;
double PI = 3.14159265358979323846;
int_64 INF = 1e18;
double EPS = 1e-9;
const int MX = (int)2e5 + 5;
const int_64 MAXI = 1e18;  // not too close to LLONG_MAX
#define MIN -1e7
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!

#define sz(x)     int(size(x))
#define pb        push_back
#define eb        emplace_back
#define F         first
#define S         second
#define mp        make_pair
#define rsz       resize
#define ins       insert
#define all(a)    (a).begin(), (a).end()
#define rall(a)   (a).rbegin(), (a).rend()
#define SORT(a)   sort(all(a))
#define RSORT(a)  sort(rall(a))
#define lb        lower_bound
#define ub        upper_bound
tcT > int lwb(const V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(const V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

#define FOR(i, a, b)         for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b)        for (int i = (a); i >= (b); --i)
#define FORE(i, a, b)        for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k)     for (int i = (a); i < (b); i += k)
#define RFORK(i, a, b, k)    for (int i = (a); i >= (b); i -= k)
#define FORA(a)              for (auto u : a)
#define SCANA(x)             for (auto &i : x) cin >> i
#define lcm(a, b)            ((a) * ((b) / gcd((a), (b))))
#define setbits(x)          __builtin_popcountll(x)
#define ctz(x)               __builtin_ctzll(x)
#define clz(x)               __builtin_clzll(x)
#define parity(x)            __builtin_parityll(x)
#define sqr(x)               ((x) * (x))
#define cube(x)              ((x) * (x) * (x))
#define isEven(x)            (0 == (x) % 2)
#define isOdd(x)             (0 != (x) % 2)
#define uceil(a, b)          ((a + b - 1) / (b))

#define dbg(x) cout << #x << " = ", __print(x), cout << '\n'


tcT, class = enable_if_t<is_arithmetic_v<T>>>
void __print(T x) { cout << x << '\n'; }

void __print(const string& s) { cout << '"' << s << '"'; }
void __print(const char* s)   { cout << '"' << s << '"'; }
void __print(char c)          { cout << '\'' << c << '\''; }

tcTU>
void __print(const pair<T, U>& p) {
    cout << "(";
    __print(p.F);
    cout << ", ";
    __print(p.S);
    cout << ")";
}

tcT>
void __print(const V<T>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); ++i) {
        __print(v[i]);
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

tcT>
void __print(const set<T>& s) {
    cout << "{";
    int i = 0;
    for (auto& x : s) {
        __print(x);
        if (++i < (int)s.size()) cout << ", ";
    }
    cout << "}";
}

tcTU>
void __print(const map<T, U>& m) {
    cout << "{";
    int i = 0;
    for (auto& [k, v] : m) {
        __print(k);
        cout << ": ";
        __print(v);
        if (++i < (int)m.size()) cout << ", ";
    }
    cout << "}";
}


/* Utility Functions */
int_64 gcd(int_64 a, int_64 b){return b==0?a:gcd(b,a%b);}
bool isPrime(int n){if(n<=1)return 0;for(int i=2;i*i<=n;++i)if(n%i==0)return 0;return 1;}
bool isUp(char ch) { return std::isupper(static_cast<unsigned char>(ch)); }
/* Power & Combinatorics */

template <typename T>
T binpow(T a,int_64 e , T mod){
    T r = 1; a %= mod;
    while(e > 0){
        if(e & 1) r = (r * a) % mod;
        a = (a * a) % mod; e >>= 1;
    } return r;}

int_64 powerMod(int_64 a,int_64 b,int_64 m){return binpow(a,b,m);}
int_64 factorialMod(int_64 n,int_64 m){int_64 r=1;for(int_64 i=1;i<=n;++i)r=r*i%m;return r;}
int addmod(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int submod(int a, int b){ a -= b; if(a < 0) a += MOD; return a; }
int_64 mulmod(int_64 a, int_64 b){ return (a*b) % MOD; }
int_64 modinv(int_64 a){ return binpow(a,(int_64)MOD-2,(int_64)MOD); }
int_64 NcR(int_64 n,int_64 r){int_64 x=1,y=1;if(n-r<r)r=n-r;while(r){x*=n;y*=r;int_64 g=gcd(x,y);x/=g;y/=g;--n;--r;}return x;}
int_64 NpR(int_64 n,int_64 r){int_64 r1=1;while(r--)r1*=n--;return r1;}

/* XOR Range Queries */
int XOR1toN(int N){int m=N%4;if(m==0)return N;if(m==1)return 1;if(m==2)return N+1;return 0;}
int XORLtoR(int L,int R){return XOR1toN(R)^XOR1toN(max(L-1,0));}
/*  TIMER  */
const auto start_time = chrono::high_resolution_clock::now();
void _timer_(){
    const auto end_time = std::chrono::high_resolution_clock::now();
    double delta = (double) chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    FIXED(2);
    cout << "[time: "<< delta <<" ms]\n";
}

// #define TIME
// #define PRAGMA
// #define ONPC

#ifdef PRAGMA
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

/*using i128 = __int128_t;*/
/* int_64 perm(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % MOD;
} */

struct ele {
    int v;
    int id;
};

void _GO() {
    // Solution Here.....
    int n, q;
    cin >> n >> q;

    vector<int64_t> vec1(n), vec2(n);

    for(int i{0}; i < n; i++){
	    cin >> vec1[i];
    }

    for(int i{0}; i < n; i++){
	    cin >> vec2[i];
    }

    for(int qq{0}; qq < q; qq++){
	    int tp, i;
	    int64_t xx;
	    cin >> tp >> i >> xx;

	    i--;

	    if(1 == tp) vec1[i] = xx;
	    else vec2[i] = xx;

	    vector<pair<int64_t, int64_t>> jbs(n);

	    for(int j{0}; j < n; j++){
		    jbs[j] = {vec2[j], vec1[j]};
	    }

	   sort(all(jbs), [](const pair<int64_t, int64_t>&_a, const pair<int64_t, int64_t>&_b){
			   return _a.first > _b.first;
			   });

			   int64_t maxi{0}, cur{0};

			   for(int j{0}; j < n; j++){
			   
			   cur += jbs[j].second;
			   int64_t finT = cur + jbs[j].first;
			   if(finT > maxi) maxi = finT;
			   }
               cout << maxi << endl;
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
    int t{1},tcase{0}; //cin >> t;
    while (tcase++,t--){
        #ifdef TIME
            cout << "[ testcase: " << tcase << " ] "<< "[[[[[[[[[[O]]]]]]]]]]" << "\n";
            _timer_();
        #endif
        _GO();
    }
    #ifdef TIME
        cout << "\nExecuted in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}

/* Look for |>
 * Non-trivial problems with simple solutions, proofs, and implementations.
 * check for ub/lb.
 * Try working from backward or endcases.
 * Do not make large assumptions without a basic proof idea.
 * Overflow, bounds, and segfaults kill solutions;check them first.
 * Use DP to relax constraints; store only the minimum required state.
 * Always carefull with Base conditions.
 * special cases (n=1?) ,Edge cases.
 * do smth instead of nothing; stay organized.
 * WRITE STUFF DOWN.
 * Eliminate Wrong Ideas First.
 * DON'T GET STUCK ON ONE APPROACH FOR TOO LONG.
 * If you dont get solution within time Just GIve Upp..
 */
