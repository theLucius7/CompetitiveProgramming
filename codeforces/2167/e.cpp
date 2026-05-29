#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    i64 x;
    std::cin >> n >> k >> x;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](i64 d) {
        std::vector<std::pair<i64, i64>> seg;
        for (int i = 0; i < n; i++) {
            i64 L = std::max(0ll, a[i] - d + 1), R = std::min(x, a[i] + d - 1);
            if (L <= R) {
                seg.push_back({L, R});
            }
        }

        if (seg.empty()) {
            return (x + 1 >= k);
        }

        std::sort(seg.begin(), seg.end());
        std::vector<std::pair<i64, i64>> nseg;
        for (auto [L, R] : seg) {
            if (nseg.empty() || L > nseg.back().second + 1) {
                nseg.push_back({L, R});
            } else {
                if (R > nseg.back().second) {
                    nseg.back().second = R;
                }
            }
        }

        i64 cnt = 0, s = 0;
        for (auto [L, R] : nseg) {
            if (s < L) {
                cnt += (L - s);
            }
            s = R + 1;
        }
        if (s <= x) {
            cnt += (x - s + 1);
        }
        return cnt >= k;
    };

    i64 lo = 0, hi = x;
    while (lo < hi) {
        i64 m = (lo + hi + 1) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }

    std::vector<std::pair<i64, i64>> seg;
    seg.reserve(n);

    for (int i = 0; i < n; i++) {
        i64 L = std::max(0ll, a[i] - lo + 1), R = std::min(x, a[i] + lo - 1);
        if (L <= R) {
            seg.push_back({L, R});
        }
    }

    std::sort(seg.begin(), seg.end());
    std::vector<std::pair<i64, i64>> nseg;
    for (auto [L, R] : seg) {
        if (nseg.empty() || L > nseg.back().second + 1) {
            nseg.push_back({L, R});
        } else {
            if (R > nseg.back().second) {
                nseg.back().second = R;
            }
        }
    }

    std::vector<i64> ans;
    i64 S = 0;
    for (auto [L, R] : nseg) {
        if (S < L) {
            for (i64 i = S; i < L && ans.size() < k; i++) {
                ans.push_back(i);
            }
            if (ans.size() == k) {
            	break;
            }
        }
        S = R + 1;
    }
    if (ans.size() < k && S <= x) {
        for (i64 i = S; i <= x && ans.size() < k; i++) {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < k; i++) {
        std::cout << ans[i] << " \n"[i == k - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
