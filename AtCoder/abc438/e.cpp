#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector nxt(N, std::vector<int>(30));
	std::vector sum(N, std::vector<i64>(30));
	for (int i = 0; i < N; i++) {
		std::cin >> nxt[i][0];
		nxt[i][0]--;
		sum[i][0] = i + 1;
	}

	for (int i = 1; i < 30; i++) {
		for (int j = 0; j < N; j++) {
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
			sum[j][i] = sum[j][i - 1] + sum[nxt[j][i - 1]][i - 1];
		}
	}

	while (Q--) {
		int T, B;
		std::cin >> T >> B;

		B--;
		i64 ans = 0;
		for (int i = 0; i < 30; i++) {
			if ((T >> i) & 1) {
				ans += sum[B][i];
				B = nxt[B][i];
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}