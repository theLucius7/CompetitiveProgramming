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
    int n, m;
    std::cin >> n >> m;

    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int x = -INT_MIN;
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int min = std::min(a[i], b[0] - a[i]), max = std::max(a[i], b[0] - a[i]);
        if (min >= x) {
            x = min;
            res[i] = min;
        } else if (max >= x) {
            x = max;
            res[i] = max;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += res[i] != a[i];
    }
    std::cout << (cnt <= 1 ? "YES" : "NO") << "\n";
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
