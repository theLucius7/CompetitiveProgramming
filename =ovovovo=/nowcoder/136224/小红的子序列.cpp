#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> da(1E6 + 10), prev(1E6 + 10, -1), dp(1E6 + 10);
    int mx = 1, tail = 0;
    for (int i = 0; i < n; i++) {
        dp[a[i]] = 1;
        prev[i] = -1;

        int x = a[i];
        for (int j = 0; j < primes.size(); j++) {
            if (x % primes[j] == 0) {
                int ndp = dp[a[i] / primes[j]] + 1;
                if (ndp > dp[a[i]]) {
                    prev[i] = da[a[i] / primes[j]];
                    dp[a[i]] = ndp;
                }
            }

            while (x % primes[j] == 0) {
                x /= primes[j];
            }

            if (x == 1) {
                break;
            } else if (isprime(x)) {
                int ndp = dp[a[i] / x] + 1;
                if (ndp > dp[a[i]]) {
                    prev[i] = da[a[i] / x];
                    dp[a[i]] = ndp;
                }
                break;
            }
        }

        if (dp[a[i]] > mx) {
            mx = dp[a[i]];
            tail = i;
        }

        da[a[i]] = i;
    }
    
    std::vector<int> ans;
    for (int i = tail; i != -1; i = prev[i]) {
        ans.push_back(a[i]);
    }
    // std::cout << mx << "\n";
    std::cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] << " \n"[i == 0];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1E6 + 10);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
