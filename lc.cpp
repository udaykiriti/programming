#include <bits/stdc++.h>
using namespace std;

#define int64_t long long
#define pb push_back
#define endl '\n'
#define Aint64_t(v) v.begin(), v.end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define SZ(x) ((int)(x).size())

#define DBG(x...)                                                              \
  cerr << "[" << #x << "] = [";                                                \
  _print(x);                                                                   \
  cerr << "]" << endl;
void _print() {}
template <typename T, typename... V> void _print(T t, V... v) {
  cerr << t;
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

const int MOD = 1e9 + 7;
const int64_t INF = 1e18;

class Solution {
public:
  vector<int64_t> dij(int s, int n, vector<vector<pair<int, int64_t>>> &adj) {

    vector<int64_t> d(n, INF);

    priority_queue<
      pair<int64_t, int>,
      vector<pair<int64_t, int>>,
      greater<pair<int64_t, int>>
    > pq;

    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
      auto [dis, u] = pq.top();
      pq.pop();

      if (dis > d[u]) continue;

      for (auto [v, w] : adj[u]) {
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          pq.push({d[v], v});
        }
      }
    }
    return d;
  }

  vector<int64_t> minCost(int n, vector<int> &p,vector<vector<int>> &roads) {

    vector<vector<pair<int, int64_t>>> e(n), l(n);
    for (auto &r : roads) {
      int u = r[0];
      int v = r[1];
      int64_t c = r[2];
      int64_t t = r[3];

      e[u].pb({v, c});
      e[v].pb({u, c});

      l[u].pb({v, c * t});
      l[v].pb({u, c * t});
    }

    vector<int64_t> ans(n);

    FOR(i, 0, n) {

      vector<int64_t> de = dij(i, n, e);
      vector<int64_t> dl = dij(i, n, l);

      int64_t mn = INF;

      FOR(j, 0, n) {

        if (de[j] == INF || dl[j] == INF) continue;

        mn = min(mn, de[j] + dl[j] + p[j]);
      }
      ans[i] = mn;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (fopen("in.txt", "r")) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  int n;
  while (cin >> n) {
    vector<int> v(n);
    FOR(i, 0, n) cin >> v[i];

    Solution sol;
    auto res = sol.solve(v);
    cout << res << endl;
  }

  return 0;
}
