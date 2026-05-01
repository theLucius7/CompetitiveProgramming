#include <bits/stdc++.h>
#define int long long
using i64 = long long;

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> s(n);
	vector<int> sum(n);
	vector<vector<int>> p(n, vector<int>(m));
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i ++ ) {
		cin >> s[i];
		mp[s[i]].push_back(i);
		for (int j = 0; j < m; j ++ ) {
			cin >> p[i][j];
			if (p[i][j] != -1) {
				sum[i] += p[i][j];
			}
		}
	}
	int Max = -1;
	for (auto [_, v] : mp) {
		int res = 0;
		for (auto id : v) {
			int b = 0;
			for (int i = 0; i < m; i ++ ) {
				if (p[id][i] == -1) {
					if (sum[id] <= Max) {
						int t = min(k, Max - sum[id] + 1);
						p[id][i] = t;
						sum[id] += t;
					} else {
						p[id][i] = 0;
					}
				} else {
					// b += p[id][i];
				}
				b += p[id][i];
			}
			if (b <= Max) {
				cout << "No\n";
				return;
			}
			res = max(res, b);
		}
		Max = res;
		// cout << Max << endl;
	}
	cout << "Yes\n";
	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < m; j ++ ) {
			cout << p[i][j] << " \n"[j == m - 1];


		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T -- ) {
		solve();
	}

	return 0;
}