#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    for (int i = 1; i < s.size(); i++) {
        int cur = i;
        while (cur >= 1 && s[cur] > s[cur - 1] + 1) {
            s[cur] = (char)(s[cur] - 1);
            std::swap(s[cur], s[cur - 1]);
            cur--;
        }
    }

    std::cout << s << "\n";
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