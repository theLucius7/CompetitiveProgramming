#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

using real = long double;

constexpr int inf = 1E9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 N;
	std::cin >> N;

	std::vector<i64> v;
	for (i64 a = 2; ; a++) {
		i128 x = a * a * a;
		if (x > N) {
			break;
		}
		for (int y = 3; y < 64; y++) {
			if (x > N) {
				break;
			}

			i64 r = std::sqrtl((real)x);
			if (r * r == x) {
				x *= a;
				continue;
			}

			v.push_back(x);

			x *= a;
		}
	}

	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());


	std::cout << v.size() + (i64)std::sqrtl((real)N) << "\n";

	return 0;
}