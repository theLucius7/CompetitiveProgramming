#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, h, w;
  cin >> n >> h >> w;
  
  queue<pair<int, int>> q;
  vector<vector<int>> dp(2, vector<int>(h + 1, -1));
  dp[0][h] = w;
  for (int step = 0; step < n; step ++) {
    int x, y;
    cin >> x >> y;
    auto &cur = dp[step & 1], &nxt = dp[~step & 1];
    fill(nxt.begin(), nxt.end(), -1);
    for (int i = 0; i <= h; i ++) {
      if (cur[i] == -1) continue;
      if (i >= x) nxt[i - x] = max(nxt[i - x], cur[i]);
      if (cur[i] >= y) nxt[i] = max(nxt[i], cur[i] - y);
    }
    if (all_of(nxt.begin(), nxt.end(), [](int x) { return x == -1; })) {
      cout << step << '\n';
      return 0;
    }
  }
  cout << n << '\n';
}