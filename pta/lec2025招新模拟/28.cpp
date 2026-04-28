#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	auto ok = [&](int x) -> bool {
		std::string s = std::to_string(x);
		return (std::pow((s[0] - '0'), 4) + std::pow((s[1] - '0'), 4) + std::pow((s[2] - '0'), 4) + std::pow((s[3] - '0'), 4)) == x;
	};

	std::vector<int> ans;
	for (int i = 1000; i <= n; i++) {
		if (ok(i)) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i];
		if (i != ans.size() - 1) {
			std::cout << " ";
		}
	}



	return 0;
}