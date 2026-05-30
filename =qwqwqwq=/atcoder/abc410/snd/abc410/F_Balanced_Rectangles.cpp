#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n, m;
    cin >> n >> m;

    auto solve = [&](vector<vector<char>> &a) {
      i64 ans = 0;
      vector<int> sum(m + 1);
      unordered_map<int, int> count;
      for (int u = 1; u <= n; u ++) {
        fill(sum.begin(), sum.end(), 0);
        for (int d = u; d <= n; d ++) {
          count.clear();
          count[0] = 1;
          int cnt = 0;
          for (int i = 1; i <= m; i ++) {
            if (a[d][i] == '#') sum[i] ++;
            else sum[i] --;
            cnt += sum[i];
            ans += count[cnt];
            count[cnt] ++;
          }
        }
      }
      cout << ans << '\n';
    };
    if (n < m) {
      vector<vector<char>> a(n + 1, vector<char>(m + 1));
      for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
          cin >> a[i][j];
        }
      }
      solve(a);
    } else {
      swap(n, m);
      vector<vector<char>> a(n + 1, vector<char>(m + 1));
      for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
          cin >> a[j][i];
        }
      }
      solve(a);
    }
  }
}