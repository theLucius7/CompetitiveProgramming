#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m, t;
LL a[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> t;

	for (int i = 1; i < n; i ++ ) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i ++ ) {
		int x, y;
		cin >> x >> y;

		a[x] -= y;
	}

	LL res = 0;
	for (int i = 1; i <= n; i ++ ) {
		res += a[i];

		if (res >= t) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";

	return 0;
}