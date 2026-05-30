#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::vector<int> b(k);
  for (int i = 0; i < k; i++) {
    std::cin >> b[i];
  }

  std::sort(b.begin(), b.end());

  int index = k - 1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (a[i] == 0) {
        a[i] = b[index--];
      }
    } else {
      if (a[i] == 0) {
        a[i] = b[index--];
      }
      if (a[i - 1] >= a[i]) {
        std::cout << "Yes\n";
        return 0;
      }
    }
  }
  std::cout << "No\n";

  return 0;
}