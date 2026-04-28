#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

i64 r(i64 a, i64 b) {
    return rnd() % (b - a + 1) + a;
}

i64 cnt = 0;
std::unordered_map<i64, i64> id;

i64 calc(i64 x, i64 y) {
    int s = x * 100000 + y;
    if (id.contains(s)) {
        return id[s];
    }
    id[s] = cnt++;
    return id[s];
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> v;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        v.push_back(a[i]);
    }


    std::vector<std::pair<int, int>> ask(q);
    for (int i = 0; i < q; i++) {
        std::cin >> ask[i].first >> ask[i].second;
        v.push_back(ask[i].first);
        v.push_back(ask[i].second);
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }

    for (int i = 0; i < q; i++) {
        ask[i].first = std::lower_bound(v.begin(), v.end(), ask[i].first) - v.begin();
        ask[i].second = std::lower_bound(v.begin(), v.end(), ask[i].second) - v.begin();
    }

    std::vector<std::vector<int>> map(5E6 + 10);
    std::vector<int> ans(5E6 + 10, -1);


    for (int i = 0; i < n; i++) {
        map[a[i]].push_back(i);
    }

    for (int x = 0; x < q; x++) {
        int a = ask[x].first, b = ask[x].second;

        if (ans[calc(a, b)] != -1) {
            std::cout << ans[calc(a, b)] << "\n";
            continue;
        }

        auto &v1 = map[a], &v2 = map[b];

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