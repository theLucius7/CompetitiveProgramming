#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;

	int i[3] {1, 2, 3};
	while (true) {
		std::cout << "? " << i[0] << " " << i[1] << " " << i[2] << std::endl;

		int p;
		std::cin >> p;

		if (p == 0) {
			break;
		}

		int x = rng() % 3;
		i[x] = p;
	}

	std::cout << "! " << i[0] << " " << i[1] << " " << i[2] << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}