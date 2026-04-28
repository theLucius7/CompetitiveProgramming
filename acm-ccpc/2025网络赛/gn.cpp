#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

i64 calc(i64 x, i64 y) {
    return x * 1000000000 + y;
}

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

    std::unordered_map<i64, i64> ans;
    for (int x = 0; x < q; x++) {
        int a, b;
        std::cin >> a >> b;

        if (ans.contains(calc(a, b))) {
            std::cout << ans[calc(a, b)] << "\n";
            continue;
        }

        auto v1 = map[a], v2 = map[b];

        if (a == b) {
            std::cout << (i64)v1.size() * (v1.size() - 1) / 2 << "\n";
            continue;
        }

        i64 sum = 0;
        for (int i = 0, j = 0; i < v1.size() && j < v2.size(); ) {
            while (j < v2.size() && v2[j] < v1[i]) {
                j++;
            }

            sum += v2.size() - j;
            i++;
        }
        ans[calc(a, b)] = sum;
        ans[calc(b, a)] = (i64)1ll * v1.size() * v2.size() - sum;

        std::cout << sum << "\n";
    }

    return 0;
}