#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 110;

int n;
int a[N], s[N];
int cnt;

void dfs (int u) {
	if (u == n) {
		cnt ++ ;
		return;
	}

	if (s[u - 1] + a[u] >= 0) {
		s[u] = s[u - 1] + a[u];
		dfs (u + 1);
	}

	if (s[u - 1] - a[u] >= 0 && a[u] != 0) {
		s[u] = s[u - 1] - a[u];
		dfs (u + 1);
	}
}

void solve () {
	cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	s[0] = a[0];

	dfs (1);

	if (cnt == 1) {
		for (int i = 0; i < n; i ++ ) {
			cout << s[i] << " \n"[i == n - 1];
		}
	} else {
		cout << "-1\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		solve ();
	}

	return 0;
}