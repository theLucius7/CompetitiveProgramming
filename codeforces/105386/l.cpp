#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, p, q;
	std::cin >> n >> p >> q;

	std::vecto<int> x(n + 1, );
	for (int i = 0; i < n; i++) {
		int X, Y;
		std::cin >> X >> Y;
		x[X + 1] = std::min(x[X + 1], Y);
	}
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