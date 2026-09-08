#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	i64 ans = 0;

	int cnt = count (s.begin (), s.end (), '0');
	ans = 1LL * cnt * (n - cnt);

	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && s[j] == s[i]) {
			j ++ ;
		}

		ans = max (ans, 1LL * (j - i) * (j - i));

		i = j;
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