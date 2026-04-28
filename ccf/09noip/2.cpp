#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int a0, a1, b0, b1;
		cin >> a0 >> a1 >> b0 >> b1;

		int res = 0;
		for (int i = 1; i < sqrt (b0); i ++ ) {
			int x;
			if (b0 % i == 0) {
				x = b1 / b0 * i;
				if (gcd (x, b0) == i && gcd (x, a0) == a1) {
					res ++ ;
				}

				x = b1 / i;
				if (gcd (x, b0) == b0 / i && gcd (x, a0) == a1) {
					res ++ ;
				}
			}
		}

		int k = (int)sqrt (b0);
		if (k * k == b0 && b0 % k == 0) {
			int x = b1 / b0 * k;
			if (gcd (x, b0) == k && gcd (x, a0) == a1) {
				res ++ ;
			}
		}

		cout << res << "\n";
	}

	return 0;
}