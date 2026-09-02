#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}

	std::vector<bool> vis(N);
	i64 ans = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i] && i != P[i] - 1) {
			int cnt = 0;
			int x = i;
			for ( ; !vis[x]; x = P[x] - 1, cnt++) {
				vis[x] = true;
			}
			ans += 1LL * cnt * (cnt - 1) / 2;
		}
	}

	std::cout << ans << "\n";


	return 0;
}

