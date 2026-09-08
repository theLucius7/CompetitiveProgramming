#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10;

struct Edge {
	int a, b, w;
}edges[N];

int n;
int d[N];

bool cmp (Edge a, Edge b) {
	return a.w > b.w;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i ++ ) {
		cin >> d[i];
	}

	int idx = 0;
	for (int i = 0; i < n - 1; i ++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		if (c > 0) {
			edges[idx ++ ] = {a, b, c};
		}
	}

	sort (edges, edges + idx, cmp);

	LL res = 0;
	for (auto edge : edges) {
		int a = edge.a, b = edge.b, w = edge.w;
		if (d[b] > 0) {
			d[b] -- ;
			res += w;
		}
	}

	cout << res << "\n";

	return 0;
}