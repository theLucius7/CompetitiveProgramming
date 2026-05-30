#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> cnt(1E7 + 10);
	for (int x = 1; x <= 3300; x++) {
		for (int y = x + 1; x * x + y * y <= 1E7; y++) {
			cnt[x * x + y * y]++;
		}
	}

	int N;
	std::cin >> N;

	std::vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 1) {
			ans.push_back(i);
		}
	}

	std::cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
	}


	return 0;
}