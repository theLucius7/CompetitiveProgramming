#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> op(Q), p(Q);
    std::vector<std::string> s(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> op[i] >> p[i];
        p[i]--;
        if (op[i] == 2){
            std::cin >> s[i];
            std::reverse(s[i].begin(), s[i].end());
        }
    }

    std::string ans;
    int u = N;
    for (int i = Q - 1; i >= 0; i--) {
        if (op[i] == 1) {
            if (u == p[i]) {
                u = N;
            }
        } else if (op[i] == 2) {
            if (u == p[i]) {
                ans += s[i];
            }
        } else {
            if (u == N) {
                u = p[i];
            }
        }
    }

    std::reverse(ans.begin(), ans.end());
    std::cout << ans << "\n";

    return 0;
}