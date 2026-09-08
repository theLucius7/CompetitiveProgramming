// LUOGU_RID: 93859038
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef pair <int, int> pii;

constexpr int N = 2E5 + 10, M = 2 * N;

int n, m, K;
int h[N], e[M], ne[M], idx;
bool deleted[M];
int d[N];
queue <int> q;
vector <int> topo;
int ans[M];

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void kahn () {
	while (q.size ()) {
		int t = q.front ();
		q.pop ();
		topo.push_back (t);

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (!deleted[i]) {
				deleted[i] = deleted[i ^ 1] = true;
				if ( -- d[j] == K - 1) {
					q.push (j);
				}
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> K;

	memset (h, -1, sizeof h);

	for (int i = 1; i <= m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add (a, b);
		add (b, a);
		d[a] ++ ;
		d[b] ++ ;
	}

	for (int i = 1; i <= n; i ++ ) {
		if (d[i] < K) {
			q.push (i);
		}
	}

	kahn ();

	ans[m] = n - topo.size ();

	for (int i = m; i >= 2; i -- ) {
		if (deleted[i * 2 - 2]) {
			ans[i - 1] = ans[i];
		} else {
			deleted[i * 2 - 1] = deleted[i * 2 - 2] = true;
			int u = e[i * 2 - 1], v = e[i * 2 - 2];
			if ( -- d[u] == K - 1) {
				q.push (u);
			}
			if ( -- d[v] == K - 1) {
				q.push (v);
			}

			kahn ();

			ans[i - 1] = n - topo.size ();
		}
	}

	for (int i = 1; i <= m; i ++ ) {
		cout << ans[i] << "\n";
	}

	return 0;
}
