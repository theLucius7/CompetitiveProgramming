#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto start = std::chrono::steady_clock::now();
	std::mt19937 rng(start.time_since_epoch().count());


	int N;
	std::cin >> N;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	auto check = [&](int M) {
		std::vector<int> B(N);
		for (int i = 0; i < N; i++) {
			B[i] = A[i] % M;
		}

		int v = 0, c = 0;
		for (int i = 0; i < N; i++) {
			if (c == 0) {
				c = 1;
				v = B[i];
			} else if (v == B[i]) {
				c++;
			} else {
				c--;
			}
		}

		c = std::count(B.begin(), B.end(), v);

		if (c > N - c) {
			std::cout << M << "\n";
			std::exit(0);
		}
	};

	check(4);

	while ((std::chrono::steady_clock::now() - start).count() < 1E9) {
		int x = rng() % N;
		int y = rng() % N;
		if (x == y) {
			y = (y + 1) % N;
		}

		int d = std::abs(A[x] - A[y]);
		for (int i = 2; i * i <= d; i++) {
			if (d % i == 0) {
				while (d % i == 0) {
					d /= i;
				}
				if (i > 2) {
					check(i);
				}
			}
		}


		if (d > 2) {
			check(d);
		}
	}

	std::cout << -1 << "\n";

	return 0;
}