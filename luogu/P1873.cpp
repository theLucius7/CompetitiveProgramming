#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 N, M;
	std::cin >> N >> M;

	std::vector<i64> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}

	auto check = [&](i64 u) -> bool {
		i64 sum = 0;
		for (int i = 0; i < N; i++) {
			sum += std::max(0LL, a[i] - u);
		}
		return sum >= M;
	};

	int lo = 1, hi = 1E9;
	while (lo < hi) {
	    int m = (lo + hi + 1) / 2;
	    if (check(m)) {
	        lo = m;
	    } else {
	        hi = m - 1;
	    }
	}
	std::cout << lo << "\n";
	return 0;
}