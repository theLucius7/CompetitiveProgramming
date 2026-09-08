// LUOGU_RID: 93838269
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 5E3 + 10, M = 2E5 + 10;

int n, m, a[3];
int h[N], e[M], ne[M], idx;
int color[N];
int belong[N], cnt;
vector <int> black[N], white[N];
bool f[N][N];
int choose[N];
int ans[N];

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs (int u, int c) {
	belong[u] = cnt;
	color[u] = c;

	if (color[u] == 1) {
		black[cnt].push_back (u);
	} else {
		white[cnt].push_back (u);
	}

	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (!color[j]) {
			if (!dfs (j, 3 - c)) {
				return false;
			}
		} else if (color[j] == c) {
			return false;
		}
	}

	return true;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	memset (h, -1, sizeof h);

	for (int i = 0; i < 3; i ++ ) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}

	for (int i = 1; i <= n; i ++ ) {
		if (!color[i]) {
			cnt ++ ;
			if (!dfs (i, 1)) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	f[0][0] = true;

	for (int i = 1; i <= cnt; i ++ ) {
		for (int j = 0; j <= a[1]; j ++ ) {
			if (black[i].size () <= j) {
				f[i][j] |= f[i - 1][j - black[i].size ()];
			}
			if (white[i].size () <= j) {
				f[i][j] |= f[i - 1][j - white[i].size ()];
			}
		}
	}

	if (!f[cnt][a[1]]) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	int j = a[1];
	for (int i = cnt; i; i -- ) {
		if (f[i - 1][j - black[i].size ()]) {
			choose[i] = 1;
			j -= black[i].size ();
		} else if (f[i - 1][j - white[i].size ()]) {
			choose[i] = 2;
			j -= white[i].size ();
		}
	}

	for (int i = 1; i <= cnt; i ++ ) {
		if (choose[i] == 1) {
			for (int j : black[i]) {
				ans[j] = 2;
			}
		} else if (choose[i] == 2) {
			for (int j : white[i]) {
				ans[j] = 2;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (!ans[i]) {
			if (sum < a[0]) {
				ans[i] = 1;
				sum ++ ;
			} else {
				ans[i] = 3;
			}
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		cout << ans[i];
	}

	cout << "\n";

	return 0;
}
