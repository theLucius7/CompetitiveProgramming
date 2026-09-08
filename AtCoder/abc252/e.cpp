#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

const int N = 2e5 + 10, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], w[M], id[M], idx;
int dist[N];
bool st[N];

void add (int a, int b, int c, int d) {
	id[idx] = d, w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra () {
	memset (dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	priority_queue <PII, vector <PII>, greater <PII>> heap;
	heap.push ({0, 1});
	
	while (heap.size ()) {
		auto t = heap.top ();
		heap.pop ();

		int ver = t.y, distance = t.x;

		if (st[ver]) continue;
		st[ver] = true;

		for (int i = h[ver]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[i] + w[i]) {
				dist[j] = dist[i] + w[i];
				heap.push ({dist[j], j});
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	memset (h, -1, sizeof h);

	for (int i = 1; i <= m; i ++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		add (a, b, c, i), add (b, a, c, i);
	}

	dijkstra ();

	for (int ver = 2; ver < n; ver ++ ) {
		for (int i = h[ver]; ~i; i = ne[i]) {
			int j = e[i];
			if (dist[ver] == dist[j] + w[i]) {
				cout << id[i] << " ";
			}
		}
	}

	cout << "\n";

	return 0;
}