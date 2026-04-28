#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q, s;
	std::cin >> n >> q >> s;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 1);
	pre[0] = s;
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
	}

	while (q--) {
		int x, y;
		std::cin >> x >> y;
		x--;

		std::cout << pre[x] + y - 1 << "\n";
	}



	return 0;
}