#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	int cnt = std::count(b.begin(), b.end(), -1);
	if (cnt == n) {
		int max = *max_element(a.begin(), a.end()), min = *min_element(a.begin(), a.end());
		std::cout << std::max(0, k - max + min + 1) << "\n";
	} else if (cnt >= 1) {
		int p = std::find_if(b.begin(), b.end(), [](int x) {return x != -1;}) - b.begin();
		int m = a[p] + b[p];
		for (int i = 0; i < n; i++) {
			if (b[i] == -1) {
				if (k + a[i] < m || a[i] > m) {
					std::cout << 0 << "\n";
					return;
				}
			} else {
				if (a[i] + b[i] != m) {
					std::cout << 0 << "\n";
					return;
				}
			}
		}
		std::cout << 1 << "\n";
	} else {
		int p = 0;
		int m = a[p] + b[p];
		for (int i = 0; i < n; i++) {
			if (b[i] == -1) {
				if (k + a[i] < m) {
					std::cout << 0 << "\n";
					return;
				}
			} else {
				if (a[i] + b[i] != m) {
					std::cout << 0 << "\n";
					return;
				}
			}
		}
		std::cout << 1 << "\n"; 
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