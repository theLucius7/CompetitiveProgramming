#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

LL f[N], g[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int cnt = 0;
	vector <LL> a;
	for (int i = 0; i < s.size (); i ++ ) {
		if (s[i] == '1') {
			cnt ++ ;
		} else {
			if (cnt != 0) {
				a.push_back ((LL)cnt * cnt);
			}
			cnt = 0;
		}
	}

	if (cnt) {
		a.push_back ((LL)cnt * cnt);
	}

	memset (f, -0x3f, sizeof f);
	memset (g, -0x3f, sizeof g);

	int n = a.size ();

	LL res = 0;
	for (int i = 0; i < n; i ++ ) {
		if (i == 0) {
			f[0] = a[i];
		} else if (i % 2 == 0) {
			f[i] = max (f[i - 2] + a[i] - a[i - 1], a[i]);
			res = max (res, f[i]);
		}
	}

	for (int i = 1; i < n; i ++ ) {
		if (i == 1) {
			g[1] = a[i];
		} else if (i % 2 == 1) {
			g[i] = max (g[i - 2] + a[i] - a[i - 1], a[i]);
			res = max (res, g[i]);
		}
	}

	cout << res << "\n";

	return 0;
}