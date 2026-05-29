#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	long double ans = 0;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i + 2; j < S.size(); j++) {
			std::string sub = S.substr(i, j - i + 1);

			if (sub[0] == 't' && sub[j - i] == 't') {
				int t = 0;
				for (int k = 0; k < j - i + 1; k++) {
					if (sub[k] == 't') {
						t++;
					}
				}
				if (t >= 3) {
					ans = std::max(ans, (long double)(t - 2) / (j - i - 1));
				}
			}
		}
	}
	std::cout << std::fixed << std::setprecision(17) << ans << "\n";

	return 0;
}