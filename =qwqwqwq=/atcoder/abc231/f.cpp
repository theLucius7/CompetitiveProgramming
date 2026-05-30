#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

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

	
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    std::vector<int> v;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        v.push_back(A[i]);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        v.push_back(B[i]);
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::vector<std::pair<int, int>> p(N);
    for (int i = 0; i < N; i++) {
        p[i] = {std::lower_bound(v.begin(), v.end(), A[i]) - v.begin(), std::lower_bound(v.begin(), v.end(), B[i]) - v.begin()};
    }

    std::sort(p.begin(), p.end(), [&](auto x, auto y) {
        if (x.first != y.first) {
            return x.first < y.first;
        } else {
            return x.second > y.second;
        }
    });


    Fenwick<int> fen(2 * N + 10);
    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        fen.add(p[i].second, 1);
        ans += i + 1 - fen.sum(p[i].second);
    }

    std::map<std::pair<int, int>, int> cnt;
    for (int i = 0; i < N; i++) {
        cnt[{p[i].first, p[i].second}]++;
    }
    for (auto [k, c] : cnt) {
        ans += 1LL * c * (c - 1) / 2;
    }


    std::cout << ans << "\n";
	

	return 0;
}