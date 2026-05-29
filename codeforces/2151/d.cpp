#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int P = 998244353;
constexpr int L = 10000000;

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
	int n;
	std::cin>> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	if (std::accumulate(a.begin(), a.end(), 0LL) != n) {
		std::cout << 0 << "\n";
		return;
	}

	std::vector<i64> cnt(n);

	for (int i = 0; i < n; i++) {
		cnt[i] = std::max(0, n - 2 * i);
	}


	i64 ans = 1, res = 0;      
    for (int i = n - 1; i >= 0; i--) {
    	int x = std::max(0LL, cnt[i] - res);

    	if (a[i] > x) {
    		std::cout << 0 << "\n";
    		return;
    	}
    	ans = (i128)ans * binom(x, a[i]) % P;
    	res += a[i];
    }

    std::cout << ans % P << "\n";
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