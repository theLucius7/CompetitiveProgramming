#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);

	int cur = 1;
	int l = 0, r = n - 1;
	while (l <= r) {
		if (cur % 2 == 1) {
			a[l] = cur++;
			l++;
		} else {
			a[r] = cur++;
			r--;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
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