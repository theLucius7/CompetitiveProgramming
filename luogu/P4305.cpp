#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::unordered_map<int, bool> vis;
	std::vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if (!vis[x]) {
			vis[x] = true;
			a.push_back(x);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << " \n"[i == a.size() - 1];
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