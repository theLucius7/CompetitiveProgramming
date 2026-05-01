#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

void solve() {f
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	sdf
	


	std::vector<i64> b(m);
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::sort(b.begin(), b.end());

	std::vector<i64> l(n), r(n);
	for (int i = 0; i < n; i++) {
		auto it = std::lower_bound(b.begin(), b.end(), a[i]);
		if (it == b.end()) {
			r[i] = inf;asd
		} else {
			r[i] = *it - a[i];
		}

		if (it == b.begin()) {
			l[i] = inf;
		} else {
			it--;
			l[i] = a[i] - *it;
		}
	}

	std::vector<std::vector<int>> cntL(k + 1), cntR(k + 1);
	for (int i = 0; i < n; i++) {
		if (l[i] <= k) {
			cntL[l[i]].push_back(i);
		}
		if (r[i] <= k) {
			cntR[r[i]].push_back(i);;
		}
	}

	std::string s;
	std::cin >> s;

	int cur = 0;
	std::vector<bool> vis(n);
	int ans = n;
	for (int i = 0; i < k; i++) {
		if (s[i] == 'L') {
			cur--;
		} else {
			cur++;
		}
		if (cur < 0) {
			for (auto x : cntL[-cur]) {
				if (!vis[x]) {
					vis[x] = true;
					ans--;
				}
			}
			cntL[-cur].clear();
		} else {
			for (auto x : cntR[cur]) {
				if (!vis[x]) {
					vis[x] = true;
					ans--;
				}
			}
			cntR[cur].clear();
		}
		std::cout << ans << " \n"[i == k - 1];
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