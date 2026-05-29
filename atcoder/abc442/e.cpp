#include <bits/stdc++.h>

using i64 = long long;

constexpr long double Pi = std::acos(-1);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<long double> a(N);
	std::vector<long double> v(N);
	for (int i = 0; i < N; i++) {
		i64 X, Y;
		std::cin >> X >> Y;
		i64 g = std::__gcd(std::abs(X), std::abs(Y));
		a[i] = std::atan2l(Y / g, X / g);
		v[i] = a[i];
 	}

	std::sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		v.push_back(v[i] + 2 * Pi);
	}

	while (Q--) {
		int A, B;
		std::cin >> A >> B;
		A--, B--;
		long double E = a[A], S = a[B];

		if (E < S - 1E-12) {
			E += 2 * Pi;
		}

		auto its = std::lower_bound(v.begin(), v.end(), S);
		auto ite = std::upper_bound(v.begin(), v.end(), E);

		std::cout << ite - its << "\n";
	}

	return 0;
}