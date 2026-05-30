#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, K;
	cin >> n >> m >> K;
	vector<int> a(n);
	for (int i = 0; i < K; i ++ ) {
		int x;
		cin >> x;
		x -- ;
		a[x] = 1;
	}
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i ++ ) {
		int u, v;
		cin >> u >> v;
		u -- , v -- ;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int k = 0; k < n; k ++ ) {
		if (!a[k]) {
			vector<vector<int>> res;
			int ans = 1;
			vector<int> st(n);
			queue<int> q;
			q.push(k);
			st[k] = 1;
			while (q.size()) {
				auto u = q.front();
				q.pop();
				if (a[u]) {
					continue;
				}
				vector<int> tmp{u};
				for (auto v : adj[u]) {
					if (st[v]) {
						continue;
					}
					// cout << v << endl;
					ans ++ ;
					st[v] = 1;
					tmp.push_back(v);
					q.push(v);
				}
				res.push_back(tmp);
			}
			// cout << k << "\n";
			if (ans != n) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
				int cnt = 0;
				for (auto v : res) {
					cnt += v.size() > 1;
				}
				cout << cnt << "\n";
				for (int i = 0; i < res.size(); i ++ ) {
					if (res[i].size() == 1) {
						continue;
					}
					cout << res[i][0] + 1 << " " << (int)res[i].size() - 1 << " ";
					for (int j = 1; j < res[i].size(); j ++ ) {
						cout << res[i][j] + 1 << " \n"[j == res[i].size() - 1];
					}
				}
			}
			return 0;
		}
	}
	cout << "No\n";


	return 0;
}