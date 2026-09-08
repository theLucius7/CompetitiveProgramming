#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10, M = 2 * N;

int h[N], e[M], ne[M], idx;

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset (h, -1, sizeof h);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add (a, b), add (b, a);
	}

	int T;
	cin >> T;

	while (T -- ) {
		int ver, k;
		cin >> ver >> k;

		set <int> s;

		function <void (int, int)> dfs = [&](int ver, int depth) {
			s.insert (ver);
			if (depth > 0) {
				for (int i = h[ver]; ~i; i = ne[i]) {
					int j = e[i];
					dfs (j, depth - 1);
				}
			}
		};

		dfs (ver, k);

		cout << accumulate (s.begin (), s.end (), 0) << "\n";
	}


	return 0;
}