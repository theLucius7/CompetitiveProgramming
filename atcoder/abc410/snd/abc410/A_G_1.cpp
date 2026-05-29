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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int k;
  cin >> k;
  cout << count_if(a.begin(), a.end(), [&](int x) { return k <= x; }) << '\n';
}