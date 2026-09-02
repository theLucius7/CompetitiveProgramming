#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x, y;
	std::cin >> n >> x >> y;

	x = std::abs(x), y = std::abs(y);

	std::string s;
	std::cin >> s;

	int a = std::count(s.begin(), s.end(), '4'), b = std::count(s.begin(), s.end(), '8');

	if (x <= b && y <= b) {
		std::cout << "YES\n";
		return;
	}

	x = std::abs(x), y = std::abs(y);

	x -= b, y -= b;

	if (x > a || y > a) {
		std::cout << "NO\n";
		return;
	}

	if (a % 2 == 0 && x + y == a) {
		std::cout << "YES\n";
		return;
	}

	std::cout << ((x + y > a) ? "NO" : "YES") << "\n";

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