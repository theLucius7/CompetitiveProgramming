#include <bits/stdc++.h>

using namespace std;

const int N = 1100, M = 500000;

int n, m;
int h[N], e[M], ne[M], idx;
int res;

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	memset (h, -1, sizeof h);

	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add (a, b), add (b, a);
	}

	for (int i = 1; i <= n; i ++ ) {
		for (int j = h[i]; ~j; j = ne[j]) {
			int ji = e[j];
			for (int k = h[ji]; ~k; k = ne[k]) {
				int ki = e[k];
				for (int x = h[ki]; ~x; x = ne[x]) {
					int xi = e[x];
					if (xi == i) {
						res ++ ;
					}
				}
			}
		}
	}

	cout << res / 6 << "\n";

	return 0;
}