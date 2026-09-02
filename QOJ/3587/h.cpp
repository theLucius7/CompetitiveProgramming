#include <bits/stdc++.h>

using i64 = long long;

void solveFirst() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> vis(n + 1);
	for (int i = 0; i < k; i++) {
		int a;
		std::cin >> a;
		vis[a] = true;
	}

	int res = 0;
	std::vector<int> stk;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			stk.push_back(i);
		} else {
			if (!stk.empty()) {
				stk.pop_back();
			} else {
				res = i;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			std::cout << i << " ";
		}
	}
	std::cout << res << "\n";
}

void solveSecond() {
	int n, k;
	std::cin >> n >> k;

	std::vector<bool> vis(n + 1);
	for (int i = 0; i < k + 1; i++) {
		int a;
		std::cin >> a;
		vis[a] = true;
	}

	std::vector<int> stk;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			stk.push_back(i);
		} else {
			if (!stk.empty()) {
				stk.pop_back();
			}
		}
	}

	std::cout << stk.front() << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string type;
	std::cin >> type;

	int t;
	std::cin >> t;

	while (t--) {
		if (type == "Alice") {
			solveFirst();
		} else {
			solveSecond();
		}
	}

	return 0;
}