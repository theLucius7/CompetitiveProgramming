#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	sort (a.begin (), a.end ());

	int x = 0, y = 0;
	for (int i = n - 1; i >= 0; i -- ) {
		if (i & 1) {
			x += a[i];
		} else {
			y += a[i];
		}
	}

	cout << abs (x - y) << "\n";

	return 0;
}