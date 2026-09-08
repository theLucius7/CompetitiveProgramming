#include <bits/stdc++.h>

using namespace std;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int l = n / 2;
	while (l > 0 && s[l] == s[l - 1]) {
		l -- ;
	}

	int r = n - l - 1;
	cout << r - l + 1 << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t -- ) {
		solve ();
	}

	return 0;
}