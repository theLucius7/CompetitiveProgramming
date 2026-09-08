#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int res = 0;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		res += min (a[i], abs(m - a[i])) * 2;
	}

	cout << res << "\n";


	return 0;
}