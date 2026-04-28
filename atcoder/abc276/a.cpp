#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string s;
	cin >> s;

	int res = -1;

	for (int i = 0; i < s.size (); i ++ ) {
		if (s[i] == 'a') {
			res = i + 1;
		}
	}

	cout << res << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}