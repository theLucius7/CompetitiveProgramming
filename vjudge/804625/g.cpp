#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+10;

#define int long long


void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i ++ ) {
		string s;
		cin >> s;
		int res = 1;
		int f = -1;
		for (auto c : s) {
			if (c == '0') {
				f = 0;
				break;
			}
		}
		if (!f) {
			cout << "kawaii\n";
			continue;
		}
		for (auto c : s) {
			res *= c - '0';
			if (res > k) {
				f = 1;
				break;
			}
		}

		if (f == 1) {
			cout << "dame\n";
		} else {
			cout << "kawaii\n";
		}
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