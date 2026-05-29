#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string t;
	std::cin >> t;

	if (t == "first") {
		int n;
		std::cin >> n;

		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}

		auto encode = [&](int x) {
			std::string s;
			while (x) {
				int c = x % 26;
				s += (char)(c + 'a');
				x /= 26;
			}
			while (s.size() < 7) {
				s += 'a';
			}
			return s;
		};

		for (int i = 0; i < n; i++) {
			std::cout << encode(a[i]);
		}
	} else {
		std::string s;
		std::cin >> s;

		auto decode = [&](std::string s) {
			int a = 0, base = 1;
			for (int i = 0; i < s.size(); i++) {
				a += (s[i] - 'a') * base;
				base *= 26;
			}

			return a;
		};

		std::vector<int> ans;

		for (int l = 0; l < s.size(); l += 7) {
			ans.push_back(decode(s.substr(l, 7)));
		};

		std::cout << ans.size() << "\n";

		for (int i = 0; i < ans.size(); i++) {
			std::cout << ans[i] << " \n"[i == ans.size() - 1];
		}
	}
	

	return 0;
}