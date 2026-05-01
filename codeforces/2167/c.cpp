#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	bool ok1 = false, ok2 = false;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] % 2 == 0) {
			ok1 = true;
		} else {
			ok2 = true;
		}
	}

	if (ok1 && ok2) {
		std::sort(a.begin(), a.end());
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