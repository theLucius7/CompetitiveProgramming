#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int n, m;
int res[N];

void dfs (int u, int cnt) {
	if (cnt == n - 1) {
		for (int i = 0; i < n; i ++ ) {
			cout << res[i] << " \n"[i == n - 1];
		}
	}
	for (int i = 1; i <= m; i ++ ) {
		if (i > u) {
			res[cnt + 1] = i;
			dfs (i, cnt + 1);
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= m - n + 1; i ++ ) {
		res[0] = i;
		dfs (i, 0);
	}

	return 0;
}