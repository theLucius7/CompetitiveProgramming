#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	int l = 1, r = n;
	for (int i = n; i >= 1; i--) {
		if ((n - i) % 2 == 0) {
			a[i] = l++;
		} else {
			a[i] = r--;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}