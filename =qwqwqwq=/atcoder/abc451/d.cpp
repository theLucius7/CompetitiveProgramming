#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::string> s;
	for (int i = 0; i < 32; i++) {
		std::string t = std::to_string(1LL << i);
		if (t.size() <= 9) {
			s.push_back(t);
		}
	}

	std::set<i64> ans;
	auto dfs = [&](auto self, std::string x) -> void {
		if (x != "") {
			ans.insert(std::stoll(x));
		}
		for (auto y : s) {
			auto t = x + y;
			if (t.size() <= 9) {
				self(self, t);
			}
		}
	};

	dfs(dfs, "");

	int cnt = 0;
	for (auto it = ans.begin(); it != ans.end(); it++, cnt++) {
		if (cnt == N - 1) {
			std::cout << *it << "\n";
		}
	}

	



	return 0;
}