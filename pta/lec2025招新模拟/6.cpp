#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> a[i];
	}

	int sum = std::accumulate(a.begin(), a.end(), 0);
	double ave = sum * 1.0 / 4;

	std::cout << std::fixed << std::setprecision(1) << "Sum = " << sum << "; Average = " << ave << "\n";

	return 0;
}