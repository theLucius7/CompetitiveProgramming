#include <bits/stdc++.h>

#define int long long

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
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> cnt(primes.size(), 1);
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            continue;
        }
        if (isprime(a[i])) {
            cnt[std::lower_bound(primes.begin(), primes.end(), a[i]) - primes.begin()]++;
            continue;
        }

        for (int j = 0; primes[j] <= a[i]; j++) {
            while (a[i] % primes[j] == 0) {
                cnt[j]++;
                a[i] /= primes[j];
            }

            if (a[i] == 1) {
                break;
            }
        }
    }

    constexpr int P = 1E9 + 7;
    int ans = 1;
    for (int i = 0; i < primes.size(); i++) {
        if (cnt[i] != 1) {
            // std::cout << primes[i] << " " << cnt[i] << "\n";
        }
        ans *= cnt[i];
        ans %= P;
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(6E5);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
