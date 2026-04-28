#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1E6 + 10, mod = 1E9 + 7;

int fact[N], infact[N];

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
    for (int i = 1; i < N; i ++ ) {
        fact[i] = (i64)fact[i - 1] * i % mod;
        infact[i] = (i64)infact[i - 1] * qmi (i, mod - 2, mod) % mod;
    }    
}

int P (int n, int m) {
	if (m > n) {
		m = n;
	}
	return (i64)fact[n] * infact[n - m] % mod;
}

int C (int n, int m) {
	return (i64)fact[n] * infact[m] % mod * infact[n - m] % mod;
}

void solve () {
	int n;
	cin >> n;

	cout << ((P (n, n) - (i64)P (n / 2 + n % 2, n / 2) * P (n / 2 + n % 2, n / 2) % mod) % mod + mod) % mod << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init ();

	solve ();

	return 0;
}