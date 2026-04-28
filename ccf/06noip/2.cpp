#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

const int N = 65, M = 32010;

int n, m;
PII master[N];
vector <PII> servent[N];
int f[M];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;

	for (int i = 1; i <= n; i ++ ) {
		int v, p, q;
		cin >> v >> p >> q;

		p *= v;

		if (!q) {
			master[i] = {v, p};
		} else {
			servent[q].push_back ({v, p});
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		for (int u = m; u >= 0; u -- ) {
			for (int j = 0; j < (1 << servent[i].size ()); j ++ ) {	
				int v = master[i].x, w = master[i].y;
				for (int k = 0; k < servent[i].size (); k ++ ) {
					if (j >> k & 1) {
						v += servent[i][k].x;
						w += servent[i][k].y;
					}
				}
				
				if (u >= v) {
					f[u] = max (f[u], f[u - v] + w);
				}
			}

		}
	}

	cout << f[m] << "\n";

	return 0;
}