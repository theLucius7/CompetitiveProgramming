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

void solve() {
	int n;
	std::cin >> n;

	i64 cnt = 0;
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i] > n) {
			break;
		}
		cnt += n / primes[i];
	}
	std::cout << cnt << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sieve(1E7 + 10);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}