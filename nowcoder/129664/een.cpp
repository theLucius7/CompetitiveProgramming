#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }
    p[0] = 0;

    std::vector<int> s(n + 1);
    std::vector<int> b;
    for (int j = 1; j <= n; j++) {
        if (p[j] == j) {
            s[j] = 1;
        } else {
            int len = p[j - 1] - p[p[j - 1] - 1];
            s[j] = s[j - len];
        }

        auto get_p = [&](int sj) {
            int cur_p = j;
            int k = b.size();
            while (k > 0) {
                int bk = b[k - 1];
                int len_k = cur_p - bk;
                bool merge = false;
                if (sj > s[bk + (j - cur_p)]) {
                    merge = true;
                } else if (sj == s[bk + (j - cur_p)]) {
                    if (j - cur_p + 1 > len_k) merge = true;
                }
                if (merge) {
                    cur_p = bk;
                    k--;
                } else break;
            }
            return cur_p;
        };

        while (true) {
            int res_p = get_p(s[j]);
            if (res_p == p[j]) break;
            if (res_p > p[j]) {
                s[j]++;
            } else {
                std::cout << -1 << "\n";
                return;
            }
        }

        int cur_p = j;
        while (b.size()) {
            int bk = b.back();
            int len_k = cur_p - bk;
            bool merge = false;
            if (s[j] > s[bk + (j - cur_p)]) merge = true;
            else if (s[j] == s[bk + (j - cur_p)] && j - cur_p + 1 > len_k) merge = true;
            if (merge) {
                cur_p = bk;
                b.pop_back();
            } else break;
        }
        b.push_back(cur_p);
    }

    for (int i = 1; i <= n; i++) {
        std::cout << s[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";
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
