#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(a[i]);
    }
    std::sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }

    std::vector<int> l(n, -1), p(n, -1);
    for (int i = 0; i < n; i++) {
        p[i] = l[a[i]];
        l[a[i]] = i;
    }

    int m;
    std::cin >> m;

    std::vector<std::tuple<int, int, int>> q(m);
    for (int i = 0; i < m; i++) {
        int lq, rq;
        std::cin >> lq >> rq;
        lq--, rq--;
        q[i] = {lq, rq, i};
    }

    std::sort(q.begin(), q.end(), [&](std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
        auto [la, ra, ida] = a;
        auto [lb, rb, idb] = b;
        return ra < rb;
    });

    int cur = 0;
    Fenwick<int> fen(n + 10);
    std::vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        auto [lq, rq, id] = q[i];
        while (cur <= rq) {
            if (p[cur] == -1) {
                fen.add(cur, 1);
            } else {
                fen.add(cur, 1);
                fen.add(p[cur], -1);
            }
            cur++;
        }
        ans[id] = fen.rangeSum(lq, rq + 1);
    }

    for (int i = 0; i < m; i++) {
        std::cout << ans[i] << "\n";
    }


	return 0;
}