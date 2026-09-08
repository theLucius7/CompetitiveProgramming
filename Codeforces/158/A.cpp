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

	int ans = 0;
	for (int l = 0, r = 0; a[l] != 0 && l < n; l = r) {
		while (r < n && a[r] == a[l]) {
			r++;
		}
		ans += r - l;
		if (ans >= k) {
			break;
		}
	}

	std::cout << ans << "\n";


	return 0;
}