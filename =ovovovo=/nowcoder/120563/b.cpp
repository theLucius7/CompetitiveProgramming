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

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	

	std::vector<std::vector<i64>> v(primes.size());

	for (int i = 0; i < n; i++){
		for (int j = 0; j < primes.size(); j++) {
			if (a[i] % primes[j] == 0) {
				v[j].push_back(i);
				if (v[j].size() == 2) {
					std::cout << a[v[j][0]] << " " << a[v[j][1]] << "\n";
					return;
				}
			}
		}
	}

	std::cout << -1 << "\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	sieve(3E3);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}