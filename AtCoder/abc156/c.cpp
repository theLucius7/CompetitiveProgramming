#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int l = 0x3f3f3f3f, r = -0x3f3f3f3f;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		l = min (l, a[i]);
		r = max (r, a[i]);
	}

	int ans = 0x3f3f3f3f;
	for (int i = l; i <= r; i ++ ) {
		int res = 0;
		for (int j = 0; j < n; j ++ ) {
			res += (a[j] - i) * (a[j] - i);
		}
		ans = min (ans, res);
	}


	cout << ans << "\n";

	return 0;
}