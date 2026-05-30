#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
    std::cin >> n;

    std::unordered_map<i64, int> map;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        map[a[i]]++;
    }


    std::unordered_map<i64, bool> vis;
    i64 max = 0;
    for (auto [k, v] : map) {
        if (!vis[k]) {
            i64 sum = k * v;
            i64 nk = k;
            while (nk % 2 == 0 && map.contains(nk / 2 * 3)) {
                nk = nk / 2 * 3;
                vis[nk] = true;
                sum += nk * map[nk];
            }
            max = std::max(max, sum);
        }
    }

    std::cout << max << "\n";

	return 0;
}