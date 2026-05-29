#include <bits/stdc++.h>

typedef long long ll;

const int mod = 100003;

ll qmi(ll a, ll b, int p) {
    ll res = 1;

    while (b) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b /= 2;
    }

    return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll n, m;
	std::cin >> m >> n;

	std::cout << (qmi(m, n, mod) - (m * qmi(m - 1, n - 1, mod)) % mod + mod) % mod << "\n";

	return 0;
}