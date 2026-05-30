#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 998244353;

LL n;

LL qmi (LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	if (n <= 2) {
		cout << "1\n";
	} else {
		LL b = 1;
		for (int i = 3; i <= n; i ++ ) {
			b = b * i % mod;
		}

		LL a = qmi (2, n - 2);

		cout << a * qmi (b, mod - 2) % mod;
	}

	return 0;
}