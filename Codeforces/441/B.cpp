#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, v;
	std::cin >> n >> v;

	std::vector<int> sum(3010);
	std::vector<std::pair<int, int>> p;

	for (int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		p.emplace_back(a, b);
	}

	std::sort (p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		auto [a, b] = p[i];
		int nsum = std::min(v, sum[a] + b);
		b -= nsum - sum[a];
		sum[a] = nsum;

		sum[a + 1] = std::min(v, sum[a + 1] + b);
	}

	std::cout << std::accumulate(sum.begin(), sum.end(), 0ll) << "\n";

	return 0;
}