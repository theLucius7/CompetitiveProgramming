#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
 
	std::vector<int> a(n), Amax(n + 1);
	std::vector<i64> b(n + 1);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		b[i + 1] = b[i] + a[i];
		Amax[i + 1] = std::max(Amax[i], a[i]);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (b[i + 1] == 2 * (i64)Amax[i + 1]) {
			cnt++;
		}
	}

	std::cout << cnt << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}