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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> v;
    auto ok = [&](int x) {
        v.push_back(a[x]);
        if (v.size() <= 2) {
            return true;
        }

        
        return (v[v.size() - 1] == v[v.size() - 2] + v[v.size() - 3]);
    };

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (ok(i)) {
            max = std::max(max, (int)v.size());
        } else {
            v.clear();
        }
    }

    std::cout << max << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}