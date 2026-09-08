// LUOGU_RID: 93787856
#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <i64, int> pli;

constexpr int N = 3E5 + 10, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
i64 dist[N];
int pre[N];
bool st[N];

void add (int a, int b, int c) {
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra (int S) {
	memset (dist, 0x3f, sizeof dist);
	dist[S] = 0;

	priority_queue <pli, vector <pli>, greater <pli>> heap;
	heap.push ({0, S});

	while (heap.size ()) {
		pli t = heap.top ();
		heap.pop ();

		int ver = t.y, distance = t.x;
		if (!st[ver]) {
			for (int i = h[ver]; ~i; i = ne[i]) {
				int j = e[i];
				if (dist[j] >= dist[ver] + w[i]) {
					pre[j] = i;
					dist[j] = dist[ver] + w[i];
					heap.push ({dist[j], j});
				}
			}
			st[ver] = true;
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	memset (h, -1, sizeof h);

	for (int i = 0; i < m; i ++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		add (a, b, c);
		add (b, a, c);
	}

	int S;
	cin >> S;

	dijkstra (S);

	i64 sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (i != S) {
			sum += w[pre[i]];
		}
	}

	cout << sum << "\n";

	for (int i = 1; i <= n; i ++ ) {
		if (i != S) {
			cout << ((pre[i] + 2) >> 1) << " ";
		}
	}

	return 0;
}