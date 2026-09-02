#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	i64 l;
	std::cin >> n >> m >> l;

	std::vector<i64> x(n);
	i64 pre = 0;
	for (int i = 0; i < n; i++) {
		i64 xx;
		std::cin >> xx;
		pre += xx;
		x[i] = pre;
	}


	i64 prey = 0;
	auto it = std::lower_bound(x.begin(), x.end(), prey + 1);
	if (it != x.end() && *it < prey + l) {
		std::cout << "YES\n";
		return 0;
	}



	for (int i = 0; i < m; i++) {
		i64 y;
		std::cin >> y;
		prey += y;

		auto nit = std::lower_bound(x.begin(), x.end(), prey + 1);
		if (nit != x.end() && *nit < prey + l) {
			std::cout << "YES\n";
			return 0;
		}
	}

	std::cout << "NO\n";
	
	return 0;
}