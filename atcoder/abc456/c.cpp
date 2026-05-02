#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	const int n = S.size();
	int ans = 0;
	for (int l = 0, r = 0; l < n; r++) {
		while (r < n - 1 && S[r] != S[r + 1]) {
			r++;
		}
		ans = (ans + (r - l + 1) * (r - l) / 2 + (r - l + 1)) % P;
		l = r + 1;
	}
	std::cout << ans << "\n";

	return 0;
}