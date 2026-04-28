#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, M = 2 * N, mod = 1e4 + 7;

int n;
int h[N], e[M], ne[M], idx;
int w[N];

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	memset (h, -1, sizeof h);

	for (int i = 0; i < n - 1; i ++ ) {
		int a, b;
		cin >> a >> b;

		add (a, b), add (b, a);
	}

	for (int i = 1; i <= n; i ++ ) {
		cin >> w[i];
	}

	int maxn = 0, ans = 0;
	for (int ver = 1; ver <= n; ver ++ ) {
		int d1 = 0, d2 = 0;
		int s = 0, t = 0;
		for (int i = h[ver]; ~i; i = ne[i]) {
			int j = e[i];
			if (w[j] > d1) {
				d2 = d1, d1 = w[j];
			} else if (w[j] > d2) {
				d2 = w[j];
			}

			s = (s + w[j]) % mod;
			t = (t + w[j] * w[j]) % mod;
		}

		maxn = max (maxn, d1 * d2);
		
		s = s * s % mod;
		ans = (ans + s - t + mod) % mod;
	}

	cout << maxn << " " << ans << "\n";

	return 0;
}