#include <bits/stdc++.h>

using i64 = long long;

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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	sieve(2E6 + 10);

	std::vector<int> cnt(32);
	for (int i = 0; i < primes.size(); i++) {
		cnt[31 - __builtin_clz(primes[i])]++;
	}

	int t;
	std::cin >> t;

	while (t--) {
		int x;
		std::cin >> x;

		int ans = 0;
		for (int i = 0; i < 32; i++) {
			if ((x >> i) & 1) {
				ans += cnt[i];
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}