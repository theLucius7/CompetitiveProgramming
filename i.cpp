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
    return n < 1E5 && n > 0 && minp[n] == n;
}

void solve() {
    int n;
    std::cin >> n;
    n++;

    int nn = n;
    std::vector<std::pair<int, int>> p;
    for (auto x : primes) {
        int cnt = 0;
        while (nn % x == 0) {
            cnt++;
            nn /= x;
        }

        if (cnt) {
            p.push_back({x, cnt});
        }

        if (nn == 1) {
            break;
        }
        if (nn <= 1E5 && isprime(nn)) {
            p.push_back({nn, 1});
            nn = 1;
            break;
        }
    }

    if (nn > 1) {
        p.push_back({nn, 1});
        nn = 1;
    }

    std::vector<int> vec;
    auto dfs = [&](this auto &&self, int i, int x) -> void {
        if (i == p.size()) {
            vec.push_back(x);
            return;
        }

        for (int t = 0, base = 1; t <= p[i].second; t++, base *= p[i].first) {
            self(i + 1, x * base);
        }
    };
    dfs(0, 1);

    std::sort(vec.begin(), vec.end());

    std::map<int, int> dp;
    dp[1] = 0;
    for (int i = 1; i < vec.size(); i++) {
        dp[vec[i]] = dp[vec[i - 1]] + (vec[i] - 1) / vec[i - 1];
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < i; j++) {
            dp[vec[i]] = std::min(dp[vec[i]], dp[vec[j]] + (vec[i] - 1) / vec[j]);
        }
    }

    std::cout << dp[n] << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(44000);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
