#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int n;
	std::cin >> n;

	std::string s, t;
	std::cin >> s >> t;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = (s[i] != t[i]);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int d;
		if (i == 0) {
			d = a[i];
		} else {
			d = a[i] ^ a[i - 1];
		}
		// std::cout << d << " \n"[i == n - 1];
		cnt += d;
	}

	// for (int i = 0; i < n; i++) {
	// 	// std::cout << a[i] << " \n"[i == n - 1];
	// }

	// std::cout << cnt << ": ";

	if (cnt == 1) {
		std::cout << (n - 1) * 2 << "\n";
	} else if (cnt == 2) {
		std::cout << 2 << "\n";
	} else if (cnt == 3) {
		std::cout << 6 << "\n";
	} else if (cnt == 4) {
		std::cout << 12 << "\n";
	} else if (cnt == 0) {
		std::cout << n + n * (n - 1) / 2 << "\n";
	} else {
		std::cout << 0 << "\n";
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}