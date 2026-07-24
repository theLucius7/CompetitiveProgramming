#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int ans = 0;
    std::vector<int> v;
    std::priority_queue<std::tuple<int, int, int>> pq;

    auto calc = [&](int len, int times) {
        len = std::max(0LL, len - times);
        int p = len / (times + 1), q = len - p * (times + 1);
        return len * 20 + (times + 1) * 5 * (p + 1) * p / 2 + q * 5 * (p + 1);
    };

    for (int l = 0, r = 0; l < n; ) {
        while (r < s.size() && s[l] == s[r]) {
            r++;
        }
        if (s[l] == '0') {
            int len = r - l;
            v.push_back(len);
            ans += (len) * 20 + 5 * (len) * (len + 1) / 2;
            pq.push({calc(len, 0) - calc(len, 1), len, 1});
        }
        l = r;
    }

    // std::cout << calc(10, 2) << "? \n";

    while (k && pq.size()) {
        auto [w, len, times] = pq.top();
        // std::cout << len << " " << times << "\n";
        pq.pop();
        ans -= w;
        pq.push({calc(len, times) - calc(len, times + 1), len, times + 1});
        k--;
    }

    std::cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
