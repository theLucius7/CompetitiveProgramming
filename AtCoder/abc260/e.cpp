#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int cnt[N];
int c[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <int> pos[m + 1];
	for (int i = 1; i <= n; i ++ ) {
		int a, b;
		cin >> a >> b;

		pos[a].push_back (i);
		pos[b].push_back (i);
	}

	int l = 1, r = 1;
	int len = 0;
	while (l <= m) {
		while (r <= m && len < n) {
			for (auto x : pos[r]) {
				if (cnt[x] == 0) {
					len ++ ;
				}
				cnt[x] ++ ;
			}
			r ++ ;
		}

		if (len == n) {
			c[r - l - 1 + 1] ++ , c[m - l + 2] -- ;
		}

		for (auto x : pos[l]) {
			if (cnt[x] == 1) {
				len -- ;
			}
			cnt[x] -- ;
		}

		l ++ ;
	}

	for (int i = 1; i <= m; i ++ ) {
		c[i] += c[i - 1];
		cout << c[i] << " \n"[i == m];
	}

	return 0;
}