#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

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
    std::map<int, std::vector<int>> M;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];

        int na = a[i];
        std::vector<std::pair<int, int>> pr;
        for (auto p : primes) {
            int cnt = 0;
            while (na % p == 0) {
                cnt++;
                na /= p;    
            }

            if (cnt) {
                pr.push_back({p, cnt});
            }
        }

        if (na > 1) {
            pr.push_back({na, 1});
        }
        
        std::vector<int> vec;
        auto dfs = [&](this auto &&self, int u, int v) -> void {
            if (u == pr.size()) {
                vec.push_back(v);
                M[v].push_back(a[i]);
                return;
            }

            for (int j = 0, base = 1; j <= pr[u].second; j++, base *= pr[u].first) {
                self(u + 1, v * base);
            }
        };
        dfs(0, 1);

    } 


    DSU dsu(1E6 + 5);
    int cnt = n, ans = 0;
    for (auto it = M.rbegin(); it != M.rend(); it++) {
        auto &[x, vec] = *it;
        for (int i = 0; i + 1 < vec.size(); i++) {
            if (dsu.merge(vec[i], vec[i + 1])) {
                cnt--;
                ans += x;

                if (cnt == 1) {
                    std::cout << ans << "\n";
                    return;
                }
            }
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(1E3 + 10);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
