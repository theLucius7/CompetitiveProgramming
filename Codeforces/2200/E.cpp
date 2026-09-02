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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        std::cout << "Bob\n";
        return;
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::vector<int> u;
        for (auto p : primes) {
            int cnt = 0;
            while (a[i] % p == 0) {
                a[i] /= p;
                cnt++;
            }

            if (cnt) {
                u.push_back(p);
            }
        }

        if (a[i] > 1) {
            u.push_back(a[i]);
        } else {
            if (u.empty()) {
                u.push_back(1);
            }
        }

        if (u.size() >= 2) {
            std::cout << "Alice\n";
            return;
        }

        b[i] = u.front();
    }

    for (int i = 1; i < n; i++) {
        // std::cout << b[i] << " \n"[i == n - 1];
        if (b[i] < b[i - 1]) {
            std::cout << "Alice\n";
            return;
        }
    }
    std::cout << "Bob\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1E3 + 10);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
