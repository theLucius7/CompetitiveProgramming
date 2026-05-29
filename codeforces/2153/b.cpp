#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    std::vector<i64> a(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> a[i];
    }

    std::vector<std::string> s(3);

    auto calc = [&](i64 x) {
        std::string S;
        while (x) {
            S += (char)(x % 2 + '0');
            x /= 2;
        }
        return S;
    };

    for (int i = 0; i < 3; i++) {
        s[i] = calc(a[i]);
        for (int j = s.size(); j < 32; j++) {
            s[i] += '0';
        }
    }

    for (int i = 0; i < 32; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            cnt += (s[j][i] == '1');
        }
        if (cnt == 2) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";

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
