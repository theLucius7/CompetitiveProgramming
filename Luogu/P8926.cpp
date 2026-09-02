#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 P = 1E9 + 7;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

i64 mul(i64 a, i64 b, i64 p) {
    i64 c = a * b - i64(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i64 power(i64 a, i64 b, i64 p) {
    i64 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

void solve() {
	i64 k, p, Q;
	std::cin >> k >> p >> Q;

	i64 cnt = 0;
	for (int i = 0; i < primes.size(); i++) {
		if (1LL * primes[i] * primes[i] > k) {
			break;
		}

		if (k % primes[i] == 0) {
			cnt++;
			while (k % primes[i] == 0) {
				k /= primes[i];
			}
		}
	}

	if (k > 1) {
		cnt++;
	}

	std::cout << 1LL * power(2, cnt, P) * (Q - p + 1) % P << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sieve(5E7 + 1);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}



	return 0;
}