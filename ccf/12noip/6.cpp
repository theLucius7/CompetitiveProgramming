#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N];
int d[N], l[N], r[N];
int b[N];

bool check (int x) {
	memset (b, 0, sizeof b);
	for (int i = 1; i <= x; i ++ ) {
		b[l[i]] -= d[i], b[r[i] + 1] += d[i];
	}

	for (int i = 1; i <= n; i ++ ) {
		b[i] += b[i - 1];
	}

	for (int i = 1; i <= n; i ++ ) {
		b[i] += a[i];
		if (b[i] < 0) {
			return true;
		}
	}

	return false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i ++ ) {
		cin >> d[i] >> l[i] >> r[i];
	}

	if (!check (m)) {
		cout << "0\n";
		return 0;
	}


	int l = 1, r = m;
	while (l < r) {
		int mid = l + r>> 1;
		if (check (mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << "-1\n";
	cout << l << "\n";

	return 0;
}