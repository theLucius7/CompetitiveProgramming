#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

#define int long long


void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	map<vector<int>, int> mp;
	vector<vector<int>> tmp;
	tmp.push_back(a);
	mp[a] = 0;
	for (int k = 1; k <= m; k ++ ) {
		vector<int> st(n);
		int p = 0;
		for (int j = 0; j < n; j ++ ) {
			if (a[j] < n) {
				st[a[j]] ++ ;
			}
		}
		while (p < n && st[p]) {
			p ++ ;
		}
		vector<int> res(n + 1);
		for (int j = 0; j < n; j ++ ) {
			if (a[j] > p || st[a[j]] > 1) {
				a[j] = p;
			}
			// cout << a[j] << " \n"[j == n - 1];
		}
		tmp.push_back(a);
		if (mp.contains(a)) {
			int x = mp[a];
			int t = (m - x) % (k - x);
			// cout << t << " " << m << " " << mp[a] << endl;
			for (int j = 0; j < n; j ++ ) {
				cout << tmp[x + t][j] << " \n"[j == n - 1];
			}
			return;
		} else {
			mp[a] = k;
		}
	}
	for (int i = 0; i < n; i ++ ) {
		cout << a[i] << " \n"[i == n - 1];
	}
}
signed main(){
	int T;
	T = 1;
	cin >> T;
	while(T--){
		solve();
	}
}