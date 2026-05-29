#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;

	int cur = -1;
	std::vector<i64> sum(m);
	std::vector<bool> vis(m);
	int p = m;
	while (q--) {
		int op;
		std::cin >> op;
		

		if (op == 1) {
			int x;
			std::cin >> x;
			cur = x;
			for (int i = 0; i < m; i++) {
				vis[i] = false;
			}
			p = m;
		} else if (op == 2) {
			int id, x;
			std::cin >> id >> x;
			id--;
			if (x == cur) {
				if (!vis[id]) {
					vis[id] = true;
					sum[id] += p;
					p--;
				}	
			}
		} else {
			int id, x;
			std::cin >> id >> x;
			id--;
			if (x == cur) {
				if (!vis[id]) {
					vis[id] = true;
				}	
			}
		}
	}

	std::vector<std::pair<int, int>> ans;
	for (int i = 0; i < m; i++) {
		ans.push_back({sum[i], i + 1});
	}
	std::sort(ans.begin(), ans.end(), [&](std::pair<int, int> a, std::pair<int, int> b) {
		if (a.first != b.first) {
			return a.first > b.first;
		}
		return a.second < b.second;
	});

	for (int i = 0; i < m; i++) {
		std::cout << ans[i].second << " " << ans[i].first << "\n";
	}
}

int main() {

	int t;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
	

	return 0;
}