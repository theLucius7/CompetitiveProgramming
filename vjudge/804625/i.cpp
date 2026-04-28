	#include <bits/stdc++.h>

	using namespace std;
	const int N = 2e5+10;

	#define int long long


	void solve(){
		int n, k;
		cin >> n >> k;
		k = n - k;
		vector<int> a(n);
		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		// for (int i = 0; i < n; i ++ ) {
		// 	cout << a[i] << " \n"[i == n - 1];
		// }

		auto check = [&](int x) -> bool {
			auto b = a;
			int l = 0, r = n - 1;
			int cnt = 0;
			while (l < r) {
				if (b[r] > x) {
					cnt ++ ;
				} else {
					int t = x - (b[r] - 1);
					while (l < r && t > 0) {
						if (b[l] > t) {
							b[l] -= t;
							t = 0;
							break;
						} else {
							t -= b[l] - 1;
							l ++ ;
						}
					}
					if (t <= 0) {
						cnt ++ ;
					} else {
						return false;
					}
				}
				r -- ;
				if (cnt >= k) {
					return true;
				}
			}
			return false;
		};

		int l = 0, r = 1e12;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (check(mid)) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		cout << l << endl;
	}
	signed main(){
		int T;
		T = 1;
		// cin >> T;
		while(T--){
			solve();
		}
	}