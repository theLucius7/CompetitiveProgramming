#include <bits/stdc++.h>

using namespace std;

string s, t;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> t;

	int l = 0, r = 0;
	while (l < s.size () || r < t.size ()) {
		if (s[l] == t[r]) {
			l ++ , r ++ ;
			continue;
		} else if (s[l - 1] == s[l - 2] && s[l - 1] == t[r]) {
			r ++ ;
			continue;
		}

		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";

	return 0;
}