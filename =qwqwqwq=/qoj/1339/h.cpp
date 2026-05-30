#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
#define int long long
void solve() {
	std::string s;
	std::cin >> s;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int y = s.size() - i;
		if (s[i] == '1') {
			ans += y;
		} else {
			ans += 2 * y;
		}
		int x = i * y;
		if (i) {
			if (s[i] == s[i - 1]) {
				ans += x * 2;
			} else {
				ans += x;
			}
		}
	}
	std::cout << ans << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}