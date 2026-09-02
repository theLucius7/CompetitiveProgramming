#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<char> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+') {
            v.push_back(s[i]);
        }
    }

    std::sort(v.begin(), v.end());
    std::cout << v.front();
    for (int i = 1; i < v.size(); i++) {
        std::cout << "+" << v[i];
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
