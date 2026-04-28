#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b, c;
	std::cin >> a >> b >> c;

	if ((a + b + c) - std::max({a, b, c}) <= std::max({a, b, c})) {
		std::cout << "These sides do not correspond to a valid triangle\n";
		return 0;
	}

	double s = (a + b + c) * 1.0 / 2;
	double area = std::sqrt(s * (s - a) * (s - b) * (s - c)), per = a + b + c;
	std::cout << std::fixed << std::setprecision(2) << "area = " << area << "; perimeter = " << per << "\n";

	return 0;
}