#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<int, int>> a(m + 1);
	a[0] = {0, 0};
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		a[i + 1] = {x, y};
	}
	

	std::sort(a.begin(), a.end());

	for (int i = 1; i <= m; i++) {
		if ((a[i].second <= a[i].first - a[i - 1].first - 1) || (a[i].second == a[i - 1].second + a[i].first - a[i - 1].first)) {
			continue;
		}
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";
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