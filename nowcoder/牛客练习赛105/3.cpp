#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1E7 + 10, mod = 1E9 + 7;

int n;
i64 fact[N], infact[N];

int qmi (int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = (i64)res * a % p;
        }
        a = (i64)a * a % p;
        k >>= 1;
    }
    return res;
}

void init () {
	fact[0] = infact[0] = 1;
    for (int i = 1; i <= 2E6; i ++ ) {
        fact[i] = (i64)fact[i - 1] * i % mod;
        infact[i] = (i64)infact[i - 1] * qmi (i, mod - 2, mod) % mod;
    }
}

int C (int n, int m) {
	return (i64)fact[n] * infact[m] % mod * infact[n - m] % mod;
}

void solve () {
	int n;
	cin >> n;

	cout << C (2 * n, n - 1) << " " << ((C (2 * n, n) - C (2 * n, n - 1)) % mod + mod) % mod << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	init ();

	while (T -- ) {
		solve ();
	}

	return 0;
}