#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<char> stk;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            stk.push_back('A');
        } else if (s[i] == 'B') {
            while (stk.size() && stk.back() == 'B') {
                stk.pop_back();
                stk.pop_back();
            }

            if (stk.empty()) {
                ans++;
            } else {
                stk.push_back('B');
            }
        } else {
            while (stk.size() && stk.back() != 'B') {
                if (stk.back() == 'A') {
                    stk.pop_back();
                } else if (stk.back() == 'C') {
                    stk.pop_back();
                    stk.pop_back();
                    stk.pop_back();
                }
            }

            if (stk.empty()) {
                ans++;
            } else {
                stk.pop_back();
                stk.pop_back();
            }
        }
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
