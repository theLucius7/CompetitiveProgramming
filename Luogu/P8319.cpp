#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> minp, primes;
std::vector<int> ans(2E6 + 1);

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

	std::cout << ans[n] << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	sieve(2E6 + 1);

	ans[1] = 1;
	for (int i = 2; i <= 2E6; i++) {
		if (minp[i] == i) {
			ans[i] = i;
		} else {
			ans[i] = ans[i - 1];
		}
	}

	while (t--) {
		solve();
	}

	return 0;
}