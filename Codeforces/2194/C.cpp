#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::string> s(k);
	for (int i = 0; i < k; i++) {
		std::cin >> s[i];
	}

	std::vector<std::array<bool, 26>> id(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			id[i][s[j][i] - 'a'] = true;
		}
	}

	std::string ans;

	auto check = [&](int x) {
		std::string t;

		for (int i = 0; i < x; i++) {
			std::vector<int> cnt(26);
			for (int j = 0; j < n / x; j++) {
				for (int c = 0; c < 26; c++) {
					cnt[c] += id[i + x * j][c];
				}
			}

			bool ok = false;
			for (int j = 0; j < 26; j++) {
				if (cnt[j] == n / x) {
					ok = true;
					t += (char)(j + 'a');
					break;
				}
			}

			if (!ok) {
				return false;
			}
		}

		ans = t;
		return true;
	};

	std::vector<int> v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (check(i)) {

				for (int u = 0; u < n / i; u++) {
					std::cout << ans;
				}
				std::cout << "\n";
				return;
			}
			v.push_back(n / i);
		}
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (check(v[i])) {
			for (int u = 0; u < n / v[i]; u++) {
				std::cout << ans;
			}
			std::cout << "\n";
			return;
		}
	}


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