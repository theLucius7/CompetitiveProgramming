#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, w;
	std::cin >> n >> w;

	std::cout << n / w * (w - 1) + n % w << "\n";
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