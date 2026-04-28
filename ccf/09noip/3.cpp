#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
int price[N];
int h[N], rh[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
bool st[N];

void add (int *h, int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa (bool flag, int *h, int u, int *d) {
	queue <int> q;
	q.push (u);

	memset (st, false, sizeof st);
	st[u] = true;

	if (!flag) {
		memset (d, 0x3f, sizeof dmin);
	}
	d[u] = price[u];

	while (q.size ()) {
		int t = q.front ();
		q.pop ();

		st[t] = false;

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (!flag && d[j] > min (d[t], price[j]) || flag && d[j] < max (d[t], price[j])) {
				if (!flag) {
					d[j] = min (d[t], price[j]);
				} else {
					d[j] = max (d[t], price[j]);
				}

				if (!st[j]) {
					st[j] = true;
					q.push (j);
				}
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	memset (h, -1, sizeof h);
	memset (rh, -1, sizeof h);

	for (int i = 1; i <= n; i ++ ) {
		cin >> price[i];
	}

	for (int i = 0; i < m; i ++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		add (h, a, b), add (rh, b, a);
		if (c == 2) {
			add (h, b, a), add (rh, a, b);
		}
	}

	spfa (false, h, 1, dmin), spfa (true, rh, n, dmax);

	int res = 0;
	for (int i = 1; i <= n; i ++ ) {
		res = max (res, dmax[i] - dmin[i]);
	}

	cout << res << "\n";

	return 0;
}