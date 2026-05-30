#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::cout << m << " " << m / (n - m + 1) + (m % (n - m + 1) != 0) << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}