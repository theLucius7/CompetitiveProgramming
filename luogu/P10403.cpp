#include <bits/stdc++.h>

using i64 = long long;

template<class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                // a[i][j] = (j == 0 ? init[i] : std::min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1], cmp));
                a[i][j] = (j == 0 ? init[i] : std::__gcd(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]));
            }
        }
    }
    // T rangeMin(int l, int r) {
    //     int k = std::__lg(r - l);
    //     return std::min(a[l][k], a[r - (1 << k)][k], cmp);
    // }
    T rangeGcd(int l, int r) {
        int k = std::__lg(r - l);
        return std::gcd(a[l][k], a[r - (1 << k)][k]);
    }
};

// auto cmpIdx = [](int x, int y) {
//         if (key[x] != key[y]) {
//             return key[x] > key[y];
//         }
//         return x > y;
// };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    RMQ<int> rmq(a);

    auto calc = [&](int x, int g) {
        int lo = x, hi = n;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (rmq.rangeGcd(x, m + 1) <= g) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        if (lo == n || rmq.rangeGcd(x, lo + 1) != g) {
            return 0LL;
        }
        int l = lo;

        lo = x, hi = n - 1;
        while (lo < hi) {
            int m = (lo + hi + 1) / 2;
            if (rmq.rangeGcd(x, m + 1) >= g) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }
        int r = lo;

        if (g == 2) {
            if ((l - x + 1) % 2 == 1) {
                l++;
            }
            if ((r - x + 1) % 2 == 1) {
                r--;
            }
            return std::max(0LL, 1LL * (l + r - 2 * x + 2) * ((r - l) / 2 + 1) / 2);
        } else {
            if ((l - x + 1) % 2 == 0) {
                l++;
            }
            if ((r - x + 1) % 2 == 0) {
                r--;
            }
            return std::max(0LL, 1LL * (l + r - 2 * x + 2) * ((r - l) / 2 + 1) / 2);
        }
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += calc(i, 2) + calc(i, 3);
    }
    std::cout << ans << "\n";

	return 0;
}