#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int res = 0;
	if (a == b && b == c) {
		if (a % 2 == 0) {
			cout << -1 << "\n";
		} else {
			cout << 0 << "\n";
		}
		return 0;
	}

	while (!((a % 2) || (b % 2) || (c % 2))) {
		res ++ ;
		int da = a / 2, db = b / 2, dc = c / 2;
		a = db + dc, b = da + dc, c = da + db;
	}

	cout << res << "\n";

	return 0;
}