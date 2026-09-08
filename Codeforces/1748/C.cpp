#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 2E5 + 10;

void solve () {
	int n;
	cin >> n;

	vector <int> a(n + 1);
	vector <i64> s(n + 1);

	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		if (a[i] != 0) {
			s[i] = s[i - 1] + a[i];
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		// cout << s[i] << " \n"[i == n];
	}

	unordered_map <i64, int> mp;

	i64 maxs = -0x7f7f7f7f7f7f7f7f, maxn = -1;
	i64 ans = 0;

	for (int i = n; i >= 1; i -- ) {
		if (a[i] != 0) {
			mp[s[i]] ++ ;
			if (maxs < mp[s[i]] || (maxs == mp[s[i]] && s[i] == 0)) {
				maxs = mp[s[i]];
				maxn = s[i];
			}
		} else {
			ans += max (1LL, maxs + (maxn == 0));
			mp.clear ();
			maxn = -1;
			maxs = -0x7f7f7f7f7f7f7f7f;
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
}//