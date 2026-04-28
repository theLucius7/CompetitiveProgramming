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

	sieve(200);

	std::vector<i64> dp(201);
	dp[0] = 1;
	for (auto p : primes) {
		for (int i = p; i <= 200; i++) {
			dp[i] += dp[i - p];
		}
	}

	int n;
	while (std::cin >> n) {
		std::cout << dp[n] << "\n";
	}




	return 0;
}