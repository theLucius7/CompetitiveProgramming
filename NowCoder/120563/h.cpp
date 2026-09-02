#include <bits/stdc++.h>

using i64 = long long;

constexpr long double eps = 0.001;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::pair<long double, long double> A, B;
	std::cin >> A.first >> A.second >> B.first >> B.second;

	if (A.second == B.second) {

		if (std::abs(std::abs(A.first - B.first) * std::abs(A.second) - 4) == 0) {
			std::cout << "0.0\n";
		} else {
			std::cout << "no answer\n";
		}
	} else if (A.first == B.first) {
		std::cout << std::fixed << std::setprecision(7) << A.first + 4.L / (std::abs(A.second - B.second)) << "\n";
	} else {
		long double k = (B.second - A.second) / (B.first - A.first), b = B.second - k * B.first;
		long double x = -b / k;
		std::cout << std::fixed << std::setprecision(7) << x + 4.L / (A.second - B.second) << "\n";
	}


	return 0;
}