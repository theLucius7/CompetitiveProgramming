#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> minp, primes;
std::vector<int> isPrime(1E5 + 10);

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            isPrime[i] = true;
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sieve(1E5 + 10);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> ans(n);
	for (int x = 1; x <= n; x++) {
		int cnt = 0;
		for (int i = 2; i <= x; i++) {
			if (!isPrime[i] && x % i == 0) {
				cnt++;
			}
		}
		ans[cnt]++;
	}
	
	while (m--) {
		int k;
		std::cin >> k;
		std::cout << ans[k] << "\n";
	}

	return 0;
}