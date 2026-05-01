#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int x, y;
    std::cin >> x >> y;

    int cnt = y / 2;
    x = std::max(0, x - y / 2 * 7);
    y %= 2;
    // std::cout << cnt << " ";
    cnt += (y * 4 + x) / 15 + ((y * 4 + x) % 15 != 0);
    std::cout << cnt << "\n";
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