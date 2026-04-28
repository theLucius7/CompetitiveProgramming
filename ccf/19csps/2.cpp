#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n;
char str[N];
int h[N], e[N], ne[N], idx;
int p[N];
LL g[N], f[N];
stack <int> stk;

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs (int u) {
	if (str[u] == '(') {
		stk.push (u);
		f[u] = f[p[u]];
		for (int i = h[u]; ~i; i = ne[i]) {
			int j = e[i];
			dfs (j);
		}
		stk.pop ();
	} else {
		if (stk.size ()) {
			int t = stk.top ();
			stk.pop ();
			g[u] = g[p[t]] + 1;
			f[u] = f[p[u]] + g[u];
			for (int i = h[u]; ~i; i = ne[i]) {
				int j = e[i];
				dfs (j);
			}
			stk.push (t);
		} else {
			f[u] = f[p[u]];
			for (int i = h[u]; ~i; i = ne[i]) {
				int j = e[i];
				dfs (j);
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cin >> str + 1;

	memset (h, -1, sizeof h);

	for (int i = 2; i <= n; i ++ ) {
		cin >> p[i];
		add (p[i], i);
	}

	dfs (1);

	LL res = 0;
	for (int i = 1; i <= n; i ++ ) {
		res ^= i * f[i];
	}

	cout << res << "\n";

	return 0;
}