#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct Edge {
	int a, b, w;
}edges[N];

int n, m;
int p[N];
int ne[N];

bool cmp (Edge a, Edge b) {
	return a.w > b.w;
}

int find (int x) {
	if (p[x] != x) {
		p[x] = find (p[x]);
	}

	return p[x];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i ++ ) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}

	sort (edges, edges + m, cmp);

	for (int i = 1; i <= n; i ++ ) {
		p[i] = i;
	}

	for (int i = 0; i < m; i ++ ) {
		if (find (edges[i].a) == find (edges[i].b)) {
			cout << edges[i].w << "\n";
			return 0;
		} else {
			if (!ne[edges[i].a]) {
				ne[edges[i].a] = edges[i].b;
			} else {
				p[find (ne[edges[i].a])] = find (edges[i].b);
			}

			if (!ne[edges[i].b]) {
				ne[edges[i].b] = edges[i].a;
			} else {
				p[find (ne[edges[i].b])] = find (edges[i].a);
			}
		}
	}

	cout << "0\n";

	return 0;
}