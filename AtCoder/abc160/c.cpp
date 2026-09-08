#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> m >> n;

	vector <int> a(n + 1);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	a[n] = a[0] + m;

	int maxv = 0;
	for (int i = 0; i < n; i ++ ) {
		maxv = max (maxv, a[i + 1] - a[i]);
	}

	cout << m - maxv << "\n";

	return 0;
}