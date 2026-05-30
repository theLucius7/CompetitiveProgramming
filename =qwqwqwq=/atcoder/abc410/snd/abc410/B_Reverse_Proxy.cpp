#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<int> cnt(n + 1);
  while (q --) {
    int x;
    cin >> x;
    if (x) {
      cout << x << ' ';
      cnt[x] ++;
    } else {
      int mi = *min_element(cnt.begin() + 1, cnt.end());
      for (int i = 1; i <= n; i ++) {
        if (cnt[i] == mi) {
          cnt[i]++;
          cout << i << ' ';
          break;
        }
      }
    }
  }
  cout << '\n';
}