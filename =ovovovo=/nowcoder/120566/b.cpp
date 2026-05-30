#include <bits/stdc++.h>

using i64 = long long;

constexpr int P = 998244353;
constexpr int L = 1000010;

int fac[L + 1], invfac[L + 1];

int binom(int n, int m) {
    if (n < m || m < 0) {
        return 0;
    }
    return 1LL * fac[n] * invfac[m] % P * invfac[n - m] % P;
}

int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % P) {
        if (b % 2) {
            res = 1LL * res * a % P;
        }
    }
    return res;
}

void solve() {
	i64 n, x, t;
	std::cin >> n >> x >> t;

	if (t == 0) {
		std::cout << (x == 0 || x == n ? 1 : 0) << "\n";
		return;
	}

	if ((t + 1) % 2 == 0) {
		i64 l = (t + 1) / 2, r = (t + 1) / 2;
		std::cout << 2LL * binom(x - 1, l - 1) * binom(n - x - 1, r - 1) % P << "\n";
	} else {
		i64 l = t / 2 + 1, r = t / 2;
		std::cout << (1LL * binom(x - 1, l - 1) * binom(n - x - 1, r - 1) % P + 1LL * binom(x - 1, r - 1) * binom(n - x - 1, l - 1) % P) % P << "\n";
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	fac[0] = 1;
    for (int i = 1; i <= L; i++) {
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
    invfac[L] = power(fac[L], P - 2);
    for (int i = L; i; i--) {
        invfac[i - 1] = 1LL * invfac[i] * i % P;
    }

    int t;
    std::cin >> t;

    while (t--) {
    	solve();
    }


	return 0;
}