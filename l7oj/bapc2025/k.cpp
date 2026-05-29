#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int h, m;
	std::cin >> h >> m;

	std::cout << (12 * (h % 60) % 360 == m ? "yes" : "no") << "\n"; 

	return 0;
}