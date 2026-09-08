#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int ans = 0;

	for (int i = 0; i < n; i ++ ) {
		vector <int> cnt (10);
		int maxn = 0, d = 0;

		for (int j = i; j < min (n, i + 100); j ++ ) {
			int x = s[j] - '0';
			if (cnt[x] == 0) {
				d ++ ;
			}

			cnt[x] ++ ;
			maxn = max (maxn, cnt[x]);

			if (maxn <= d) {
				ans ++ ;
			}
		}
	}

	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
 		solve ();
	}

	return 0;
}