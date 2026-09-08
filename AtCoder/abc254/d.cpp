#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int primes[N], cnt;
bool st[N];

void get_primes (int n) {
	for (int i = 2; i <= n; i ++ ) {
		if (!st[i]) {
			primes[cnt ++ ] = i;
		}
		for (int j = 0; primes[j] <= n / i; j ++ ) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) {
				break;
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// get_primes (n);

	vector <int> f(n + 1);
	iota (f.begin (), f.end (), 0);

	for (int i = 2; i * i <= n; i ++ ) {
		for (int j = i; j <= n; j += i) {
			while (f[j] % (i * i) == 0) {
				f[j] /= i * i;
			}
		}
	}

	int res = 0;

	vector <int> cnt(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		res += cnt[f[i]] * 2 + 1;
		cnt[f[i]] ++ ;
	}

	cout << res << "\n";

	return 0;
}