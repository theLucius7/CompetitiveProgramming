#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int sum = 0;
    std::vector<int> cnt(2);
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
        cnt[0] += (s[i] == '2');
        cnt[1] += (s[i] == '3');
    }

    sum %= 9;

    for (int i = 0; i <= cnt[0]; i++) {
        for (int j = 0; j <= cnt[1]; j++) {
            if ((sum + i * 2 + j * 6) % 9 == 0) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    std::cout << "NO\n";
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