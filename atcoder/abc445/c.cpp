#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;


	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		A[i]--;
	}

	std::vector<int> ans(N, -1);
	auto dfs = [&](auto self, int x) -> int {
		if (x == A[x]) {
			return x;
		}

		ans[x] = self(self, A[x]);
		return ans[x];
	};

	for (int i = 0; i < N; i++) {
		if (ans[i] == -1) {
			ans[i] = dfs(dfs, i);
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << ans[i] + 1 << " \n"[i == N - 1];
	}

	return 0;
}