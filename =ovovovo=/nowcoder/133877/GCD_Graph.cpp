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
    int l, r, n;
    std::cin >> l >> r >> n;

    int nn = n;
    std::vector<int> vec;
    for (auto x : primes) {
        if (nn % x == 0) {
            vec.push_back(x);
            while (nn % x == 0) {
                nn /= x;
            }
        }

        if (nn == 1) {
            break;
        }
        if (isprime(nn)) {
            vec.push_back(nn);
            break;
        }
    }

    // for (auto x : vec) {
    //     std::cout << x << " ";
    // }
    // std::cout << "?";

    int res = 0;
    for (int i = 1; i < (1 << vec.size()); i++) {
        int cnt = 0;
        int x = 1;
        for (int j = 0; j < vec.size(); j++) {
            if ((i >> j) & 1) {
                cnt++;
                x *= vec[j];
            }
        }
        // std::cout << x << " \n"[i == (1 << vec.size()) - 1];

        // std::cout << cnt << ": " << x << "? " << r / x << " " << (l - 1) / x << "\n";
        if (cnt & 1) {
            res += r / x - (l - 1) / x;
        } else {
            res -= r / x - (l - 1) / x;
        }
    }

    int ans = r - l + 1 + res;

    std::deque<int> q;
    std::unordered_map<int, bool> vis;
    for (int x = n - 1; x >= std::max(0LL, n - 300); x--) {
        if (std::gcd(x, n) == 1) {
            q.push_back(x);
            vis[x] = true;
            // std::cout << x << ", " << n << "\n";
        }
    }

    std::vector<int> pi;
    // std::cout << r << "!\n";
    for (int i = std::max(l, n - 300); i <= r; i++) {
        if (!vis[i]) {
            bool ok = false;
            for (int j = i + 1; j <= n; j++) {
                if (std::gcd(i, j) == 1 && vis[j]) {
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                // std::cout << i << "?\n";
                pi.push_back(i);
                ans++;
            }
        }
    }

    // for (auto i : pi) {
    //     bool ok = false;
    //     for (int j = i + 1; j <= n; j++) {
    //         if (std::gcd(i, j) == 1) {
    //             for (int k = j + 1; k <= n; k++) {
    //                 if (std::gcd(j, k) == 1 && vis[k]) {
    //                     ok = true;
    //                     break;
    //                 }
    //             }
    //         }

    //         if (ok) {
    //             break;
    //         }
    //     }

    //     if (!ok) {
    //         ans++;
    //     }
    // }

    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1E7 + 10);
    // std::cout << minp[1] << "\n";

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
