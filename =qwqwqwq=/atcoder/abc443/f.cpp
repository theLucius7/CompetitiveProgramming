#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	if (N % 10 == 0) {
		std::cout << "-1\n";
		return 0;
	}

	// LastDight yushu
	std::queue<int> q;
	std::vector<int> prev(N * 10 + 10);

	for (int i = 1; i <= 9; i++) {
		q.push((i % N) * 10 + i);
		prev[(i % N) * 10 + i] = -1;
	}

	int T = -1;
	while (!q.empty()) {
		int t = q.front();
		int d = t % 10, y = (t - d) / 10;
		q.pop();

		if (y == 0) {
			T = t;
			break;
		}

		for (int x = d; x <= 9; x++) {
			int ny = (y * 10 + x) % N;

			if (!prev[ny * 10 + x]) {
				q.push(ny * 10 + x);
				prev[ny * 10 + x] = t;
			}
		}
	}

	if (T == -1) {
		std::cout << "-1\n";
		return 0;
	}

	std::vector<int> ans;
	ans.push_back(T % 10);
	while (prev[T] != -1) {
		T = prev[T];
		ans.push_back(T % 10);
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		std::cout << ans[i];
	}


	return 0;
}