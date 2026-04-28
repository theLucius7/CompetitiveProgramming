#include <bits/stdc++.h>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n;
string s[N], p;
int cur;
bool used[26];

int dfs () {
	char c = s[cur][2];
	if (used[c - 'a']) {
		return -1;
	}
	
	used[c -'a'] = true;

	auto i = s[cur].begin () + 4;
	int b = 0, e = 0;

	if (*i == 'n') {
		b = INF;
		i ++ ;
	} else {
		while (isdigit (*i)) {
			b = 10 * b + *i - '0';
			i ++ ;
		}
	}

	i ++ ;

	if (*i == 'n') {
		e = INF;
		i ++ ;
	} else {
		while (isdigit (*i)) {
			e = 10 * e + *i - '0';
			i ++ ;
		}
	}

	int d;
	if (b <= e) {
		if (e - b >= 100) {
			d = 1;
		} else {
			d = 0;
		}
	} else {
		d = -1;
	}

	cur ++ ;

	int res = 0;
	while (cur < n && s[cur][0] == 'F') {
		res = dfs ();

		if (res == -1) {
			return -1;
		}
	}

	if (cur == n) {
		return -1;
	}

	used[c - 'a'] = false;

	cur ++ ;
	
	if (d == -1) {
		return 0;
	}

	return res + d;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		cin >> n >> p;

		getline (cin, s[0]);

		for (int i = 0; i < n; i ++ ) {
			getline (cin, s[i]);
		}

		int exp;
		if (p.size () == 4) {
			exp = 0;
		} else {
			exp = stoi (p.substr (4, p.size () - 5));
		}

		cur = 0;
		memset (used, false, sizeof used);

		int ans = 0;
		while (cur < n && s[cur][0] == 'F') {
			int x = dfs ();

			if (x == -1) {
				ans = -1;
				break;
			}

			ans = max (ans, x);
		}

		if (cur != n) {
			ans = -1;
		}

		if (ans == -1) {
			cout << "ERR\n";
		} else if (ans == exp) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}