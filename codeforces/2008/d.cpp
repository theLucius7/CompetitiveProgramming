#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
	}

	std::string s;
	std::cin >> s;

	std::vector<int> res(n);
	std::vector<bool> vis(n);
	std::vector<int> v;
	int cnt;
	auto dfs = [&](auto self, int i) -> void {
		vis[i] = true;
		if (s[i] == '0') {
			cnt++;
		}
		v.push_back(i);

		int p = a[i];
		if (!vis[p]) {
			self(self, p);
		}
	};

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cnt = 0;
			v.clear();
			dfs(dfs, i);

			for (int i = 0; i < v.size(); i++) {
				res[v[i]] = cnt;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << res[i] << " \n"[i == n - 1];
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