#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::unordered_map<int, std::vector<int>> map;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        map[a].push_back(i);
    }

    std::map<std::pair<int, int>, i64> ans;
    for (int j = 0; j < q; j++) {
        int a, b;
        std::cin >> a >> b;

        if (ans.contains({a, b})) {
            std::cout << ans[{a, b}] << "\n";
            continue;
        }

        auto &v1 = map[a], &v2 = map[b];

        bool flag = false;
        if (v2.size() < v1.size()) {
            flag = true;
            std::swap(v1, v2);
        }

        i64 sum = 0;
        if (a == b) {
            sum = (i64)v1.size() * (v1.size() - 1) / 2;
            std::cout << sum << "\n";
            continue;
        } else {
            for (int i = 0; i < v1.size(); i++) {
                auto it = std::lower_bound(v2.begin(), v2.end(), v1[i]);
                if (it != v2.end()) {
                    sum += (i64)(v2.end() - it);
                } else {
                    break;
                }
            }
        }
        if (!flag) {
            ans[{a, b}] = sum;
            ans[{b, a}] = (i64)1ll * v1.size() * v2.size() - sum;
            std::cout << sum << "\n";
        } else {
            ans[{b, a}] = sum;
            ans[{a, b}] = (i64)1ll * v1.size() * v2.size() - sum;
            std::cout << (i64)1ll * v1.size() * v2.size() - sum << "\n";
            std::swap(v1, v2);
        }
    }

    return 0;
}