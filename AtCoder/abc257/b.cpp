#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector <int> a(m + 1);
	a[m] = n;
	for (int i = 0; i < m; i ++ ) {
		cin >> a[i];
		a[i] -- ;
	}

	for (int i = 0; i < k; i ++ ) {
		int j;
		cin >> j;

		j -- ;

		if (a[j] + 1 < a[j + 1]) {
			a[j] ++ ;
		}
	}

	for (int i = 0; i < m; i ++ ) {
		cout << a[i] + 1 << " \n"[i == n - 1];
	}

	return 0;
}