#include <bits/stdc++.h>

using namespace std;

int n;
bool st[26];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		int m;
		cin >> m;

		string s;
		cin >> s;

		memset (st, false, sizeof st);

		int res = 0;
		for (int i = 0; i < m; i ++ ) {
			if (st[s[i] - 'A']) {
				res ++ ;
			} else {
				st[s[i] - 'A'] = true;
				res += 2;
			}
		}

		cout << res << "\n";
	}


	return 0;
}