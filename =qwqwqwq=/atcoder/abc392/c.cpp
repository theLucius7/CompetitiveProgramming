#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> P(N), Q(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		P[i]--;
	}
	for (int i = 0; i < N; i++) {
		std::cin >> Q[i];
		Q[i]--;
	}
	std::vector<int> iQ(N);
	for (int i = 0; i < N; i++) {
		iQ[Q[i]] = i;		
	}

	for (int i = 0; i < N; i++) {
		std::cout << Q[P[iQ[i]]] + 1 << " \n"[i == N - 1];
	}

	return 0;
}