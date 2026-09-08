#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void get_primes (int n) {
	for (int i = 2; i <= n; i ++ ) {
		if (!st[i]) {
			primes[cnt ++ ] = i;
		}

		for (int j = 0; primes[j] <= n / i; j ++ ) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LL n;
	cin >> n;

	get_primes (N);

	int res = 0;
	for (int i = 0; i < cnt; i ++ ) {
		if ((LL) primes[i] * primes[i] * primes[i] >= n) {
			break;
		}

		LL x = n / primes[i] / primes[i] /primes[i];
		res += upper_bound (primes, primes + i, x) - primes;
	}

	cout << res << "\n";

	return 0;
}