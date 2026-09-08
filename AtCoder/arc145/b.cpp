#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, a, b;


int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> a >> b;

	if (b >= a) {
		n -= a - 1;
		if (n <= 0) {
			cout << "0\n";
			return 0;
		}
		cout << n << "\n";
		return 0;
	}

	n -= a - 1;

	if (n <= 0) {
		cout << 0;
		return 0;
	}

	LL k = n / a, r = n % a;
	cout << k * b + min (b, r) << "\n";

	return 0;
}