#include <bits/stdc++.h>

using i64 = long long;

#define int long long

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

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    auto count = [&](int k) {
        Fenwick<int> t(N + 10);
        int cur = 0;
        i64 res = 0;
        for (int l = 0, r = 0; l < N; l++) {
            while (r < N && cur + t.rangeSum(P[r] + 1, N + 1) <= k) {
                cur += t.rangeSum(P[r] + 1, N + 1);
                t.add(P[r], 1);
                r++;
            }

            res += r - l;

            cur -= t.rangeSum(0, P[l]);
            t.add(P[l], -1);
        }
        return res;
    };

    if (K == 0) {
        std::cout << count(K) << "\n";
    } else {
        std::cout << count(K) - count(K - 1) << "\n";
    }


	return 0;
}	