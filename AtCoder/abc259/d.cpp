#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3010;

int n;
int sx, sy, tx, ty;
int x[N], y[N], r[N];
int p[N];

int find (int x) {
	if (p[x] != x) {
		p[x] = find (p[x]);
	}

	return p[x];
}

LL dis2 (int x1, int y1, int x2, int y2) {
	return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	cin >> sx >> sy >> tx >> ty;

	for (int i = 0; i < n; i ++ ) {
		cin >> x[i] >> y[i] >> r[i];
	}

	for (int i = 0; i <= n + 1; i ++ ) {
		p[i] = i;
	}

	for (int i = 0; i < n; i ++ ) {
		if (dis2 (x[i], y[i], sx, sy) == 1LL * r[i] * r[i]) {
			p[find (i)] = find (n);
		}
		if (dis2 (x[i], y[i], tx, ty) == 1LL * r[i] * r[i]) {
			p[find (i)] = find (n + 1);
		}

		for (int j = i + 1; j < n; j ++ ) {
			LL d = dis2 (x[i], y[i], x[j], y[j]);
			int a = abs (r[i] - r[j]);
			int b = r[i] + r[j];
			if (1LL * a * a <= d && d <= 1LL * b * b) {
				p[find (i)] = find (j);
			}
		}
	}

	if (find (n) == find (n + 1)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}