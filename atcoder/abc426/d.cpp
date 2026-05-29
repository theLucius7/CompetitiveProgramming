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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int cnt[2] {};
    for (int i = 0; i < N; i++) {
        cnt[S[i] - '0']++;
    }

    int max[2] {};
    for (int x = 0, y = -1; x <= N; x++) {
        if (x < N && S[x] == '0') {

        } else {
            max[0] = std::max(max[0], x - y - 1);
            y = x;
        }
    }
    for (int x = 0, y = -1; x <= N; x++) {
        if (x < N && S[x] == '1') {

        } else {
            max[1] = std::max(max[1], x - y - 1);
            y = x;
        }
    }

    std::cout << std::min((cnt[0] - max[0]) * 2 + cnt[1], (cnt[1] - max[1]) * 2 + cnt[0]) << "\n";
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
