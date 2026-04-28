#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> H(n), V(n);
	for (int i = 0; i < n; i++) {
		std::cin >> H[i] >> V[i];
	}

	std::vector<int> stk;
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		while (!stk.empty() && H[i] >= H[stk.back()]) {
			stk.pop_back();
		}

		if (!stk.empty()) {
			ans[stk.back()] += V[i];
		}

		stk.push_back(i);
	}

	stk.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!stk.empty() && H[i] >= H[stk.back()]) {
			stk.pop_back();
		}

		if (!stk.empty()) {
			ans[stk.back()] += V[i];
		}

		stk.push_back(i);
	}

	std::cout << *max_element(ans.begin(), ans.end()) << "\n";


	return 0;
}