#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
string s[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		cin >> n;

		unordered_map <string, bool> mp;
		for (int i = 0; i < n; i ++ ) {
			cin >> s[i];
			mp[s[i]] = true;
		}

		string res;
		for (int i = 0; i < n; i ++ ) {
			bool ok = false;
			for (int j = 1; j < s[i].size (); j ++ ) {
				if (mp[s[i].substr (0, j)] && mp[s[i].substr (j, s[i].size () - j)]) {
					res += '1';
					ok = true;
					break;
				}
			}

			if (!ok) {
				res += '0';
			}
		}

		cout << res << "\n";
	}

	return 0;
}