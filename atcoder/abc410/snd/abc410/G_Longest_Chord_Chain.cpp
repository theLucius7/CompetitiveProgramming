#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> vec(2 * n + 1);
  for (int i = 0; i < n; i ++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    vec[x].push_back(-y);
    vec[y].push_back(-x - 2 * n);
  }
  vector<int> dp;
  for (int i = 1; i <= 2 * n; i ++) {
    sort(vec[i].begin(), vec[i].end(), greater<int>());
    for (auto p : vec[i]) {
      auto iter = lower_bound(dp.begin(), dp.end(), p);
      if (iter == dp.end()) dp.push_back(p);
      else *iter = p;
    }
  }
  cout << dp.size() << '\n';
}