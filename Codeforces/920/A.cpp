#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    int max = 0, pre;
    for (int i = 0; i < k; i++) {
        int v;
        std::cin >> v;

        if (i == 0 && i == k - 1) {
            max = std::max({max, n - v + 1, v});
        } else if (i == 0) {
            max = std::max(max, v);
        } else if (i == k - 1) {
            max = std::max(max, n - v + 1);
        } 
        if (i > 0) {
            max = std::max(max, (v - pre + 2) / 2);
        }

        pre = v;
    }

    std::cout << max << "\n";


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