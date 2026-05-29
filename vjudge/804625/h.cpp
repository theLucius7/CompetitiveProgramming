#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

#define int long long

int get(int x) {
	int cnt = 0;
	while (x) {
		x /= 10;
		cnt ++ ;
	}
	return cnt;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	int cnt1 = 0, cnt2 = 0;
	vector<int> st(m + 1);
	vector<int> ans(m + 1), res(m + 1);
	for (int i = 0; i < n; i ++ ) {
		if (!st[a[i]]) {
			cnt1 += get(a[i]);
			cnt2 ++ ;
		}
		st[a[i]] = 1;
		ans[a[i]] = cnt1;
		res[a[i]] = cnt2;
	}
	for (int i = 1; i <= m; i ++ ) {
		cout << ans[i] + res[i] - 1 << " \n"[i == m];
	}
}

signed main(){
	int T;
	T = 1;
	// cin >> T;
	while(T--){
		solve();
	}
}