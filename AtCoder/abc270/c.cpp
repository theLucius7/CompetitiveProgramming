#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int N = 2e5 + 10, M = 2 * N;

int h[N], e[M], ne[M], idx;
int n, s, t;
int ans[N];

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs (int u, int fa, int cnt) {
	if (u == t) {
		for (int i = 0; i <= cnt; i ++ ) {
			cout << ans[i] << " \n"[i == cnt];
		}
		return;
	}
	
	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (j != fa) {
			ans[cnt + 1] = j;
			dfs (j, u, cnt + 1);
		}
	}
}

void solve () {
	memset (h, -1, sizeof h);
	
	cin >> n >> s >> t;
	
	for (int i = 0; i < n - 1; i ++ ) {
		int a, b;
		cin >> a >> b;
		add (a, b), add (b, a);
	} 
	
	ans[0] = s;
	dfs (s, -1, 0);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 