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
  vector<int> a(n);
  for (int i = 0; i < n; i ++) a[i] = i + 1;
  int s = 0;
  while (q --) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      x --;
      a[(s + x) % n] = y;
    } else if (op == 2) {
      int x;
      cin >> x;
      x --;
      cout << a[(s + x) % n] << '\n';
    } else {
      int x;
      cin >> x;
      s = (s + x) % n;
    }
  }
}