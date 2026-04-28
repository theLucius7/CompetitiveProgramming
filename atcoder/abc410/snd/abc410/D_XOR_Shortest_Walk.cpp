#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m --) {
    int u, v, w;
    cin >> u >> v >> w;
    u --, v --;
    g[u].emplace_back(v, w);
  }
  vector<vector<int>> dp(n, vector<int>(1 << 10, 0));
  dp[0][0] = 1;
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [u, s] = q.front();
    q.pop();
    for (auto [v, w] : g[u]) {
      int t = s ^ w;
      if (!dp[v][t]) {
        dp[v][t] = 1;
        q.emplace(v, t);
      }
    }
  }
  for (int i = 0; i < 1024; i ++) {
    if (dp[n - 1][i]) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}