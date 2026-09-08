#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;

		int d1 = x - a, d2 = y - b;
		if (d1 > 0) {
			c -= x - a;
		} 
		if (d2 > 0) {
			c -= y - b;
		}

		if (c >= 0) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}

	return 0;
}