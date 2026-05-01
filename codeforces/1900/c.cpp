#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    auto dfs = [&](auto self, int x) -> int {
        if (l[x] == -1 && r[x] == -1) {
            return 0;
        }

        int ans = n;
        if (l[x] != -1) {
            ans = self(self, l[x]) + (s[x] != 'L');
        }
        if (r[x] != -1) {
            ans = std::min(ans, self(self, r[x]) + (s[x] != 'R'));
        }
        return ans;
    };
    int ans = dfs(dfs, 0);
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}