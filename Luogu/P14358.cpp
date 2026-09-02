#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n * m);
	for (int i = 0; i < n * m; i++) {
		std::cin >> a[i];
	}
	int a0 = a[0];
	std::sort(a.begin(), a.end());

	int id = n * m - (int)(std::lower_bound(a.begin(), a.end(), a0) - a.begin());

	// std::cout << id << "\n";

	int x = id / n;
	if (id % n == 0) {
		std::cout << x << " " << (x % 2 == 1 ? n : 1) << "\n";
	} else {
		std::cout << x + 1 << " " << ((x + 1) % 2 == 0 ? (n - (id % n) + 1) : (id % n)) << "\n";
	}


	return 0;
}