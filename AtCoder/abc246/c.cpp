#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, x;
	cin >> n >> k >> x;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		int t = min (k, a[i] / x);
		a[i] -= t * x;
		k -= t;
	}

	sort (a.begin (), a.end ());

	cout << accumulate (a.begin (), a.end () - min (n, k), 0LL) << "\n";

	return 0;
}