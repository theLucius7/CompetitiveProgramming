#include <bits/stdc++.h>

using i64 = long long;

using namespace std;


constexpr i64 mod = 1E9 + 7;

void solve() {
	int l, r;
	std::cin >> l >> r;

	if (r - l + 1 >= 10) {
		std::cout << "0\n";
		return;
	}

	i64 ans = 1;
	for (int i = l; i <= r; i++) {
		std::string s = std::to_string(i);

		for (int j = 0; j < s.size(); j++) {
			ans *= 1LL * (s[j] - '0');
			ans %= mod;
		}
	}
	std::cout << ans << "\n";
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}