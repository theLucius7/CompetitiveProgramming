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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::map<int, int> map;
    for (int i = 1; i <= N; i++) {
        map[i] = 1;
    }

    while (Q--) {
        int X, Y;
        std::cin >> X >> Y;

        int ans = 0;

        std::vector<int> v;
        for (auto [a, cnt] : map) {
            if (a > X) {
                break;
            }
            ans += cnt;
            v.push_back(a);
        }


        if (ans) {
            for (int i = 0; i < v.size(); i++) {
                map.erase(v[i]);
            }
            map[Y] += ans;
        }
        std::cout << ans << "\n";
    }

    return 0;
}
