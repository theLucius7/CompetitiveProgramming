#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

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
    u64 n;
    std::cin >> n;

    std::vector<i128> ans;
    i128 p = 10;
    for (int k = 1; k <= 18; k++) {
        i128 d = p + 1;
        if (n % d == 0) {
            ans.push_back(n / d);
        }
        p *= 10;
    }

    if (ans.size() == 0) {
        std::cout << 0 << "\n";
    } else {
        std::cout << ans.size() << "\n";
        std::sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << " \n"[i == ans.size() - 1];
        }
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