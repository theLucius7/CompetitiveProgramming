#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <vector <int>> g(n, vector <int> (n));
	for (int i = 0; i < n; i ++ ) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j ++ ) {
			g[i][j] = (s[j] - '0');
		}
	}

	vector <int> res(n);
	for (int x = 0; x < n; x ++ ) {
		for (int y = 0; y < n; y ++ ) {
			vector <int> ans;

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x + i, b = y + i;
				if (a >= n) {
					a -= n;
				}
				if (b >= n) {
					b -= n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x, b = y + i;
				if (a >= n) {
					a -= n;
				}
				if (b >= n) {
					b -= n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x + i, b = y;
				if (a >= n) {
					a -= n;
				}
				if (b >= n) {
					b -= n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x - i, b = y - i;
				if (a >= n) {
					a -= n;
				}
				if (a <= 0) {
					a += n;
				}

				if (b >= n) {
					b -= n;
				}
				if (b <= 0) {
					b += n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x, b = y - i;
				if (a >= n) {
					a -= n;
				}
				if (a <= 0) {
					a += n;
				}

				if (b >= n) {
					b -= n;
				}
				if (b <= 0) {
					b += n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x - i, b = y;
				if (a >= n) {
					a -= n;
				}
				if (a <= 0) {
					a += n;
				}

				if (b >= n) {
					b -= n;
				}
				if (b <= 0) {
					b += n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x - i, b = y + i;
				if (a >= n) {
					a -= n;
				}
				if (a <= 0) {
					a += n;
				}

				if (b >= n) {
					b -= n;
				}
				if (b <= 0) {
					b += n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}

			ans.clear ();
			for (int i = 0; i < n; i ++ ) {
				int a = x + i, b = y - i;
				if (a >= n) {
					a -= n;
				}
				if (a <= 0) {
					a += n;
				}

				if (b >= n) {
					b -= n;
				}
				if (b <= 0) {
					b += n;
				}
				ans.push_back (g[a][b]);
			}
			for (int i = 0; i < n; i ++ ) {
				if (res[i] < ans[i]) {
					res = ans;
				}
			}
		}
	}

	for (auto x : res) {
		cout << x;
	}

	return 0;
}