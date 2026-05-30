#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	
	int N, W;
	std::cin >> N >> W;

	std::vector<std::array<int, 3>> P(N);
	std::vector<int> belong(N), mx(N), cnt(N);
	std::map<int, int> id;

	for (int i = 0; i < N; i++) {
		std::cin >> P[i][0] >> P[i][1];
		P[i][2] = i;
	}

	std::sort(P.begin(), P.end());

	for (auto [x, y, i] : P) {
		belong[i] = id[x];
		cnt[belong[i]]++;
		mx[belong[i]] = std::max(mx[belong[i]], y);
		id[x]++;
	}


	int Q;
	std::cin >> Q;

	while (Q--) {
		int T, A;
		std::cin >> T >> A;
		A--;

		int k = belong[A];
		std::cout << (cnt[k] != W || mx[k] > T ? "Yes" : "No") << "\n";
	}

	return 0;
}