#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i].first;
		P[i].second = i;
	}

	std::sort(P.begin(), P.end(), std::greater<>());

	std::vector<int> ans(N);
	int k = 1;
	for (int i = 0, j = 0; i < N; i = j) {
		while (j < N && P[j].first == P[i].first) {
			ans[P[j].second] = k;
			j++;
		}
		k += j - i;
	}

	std::sort(P.begin(), P.end(), [&](auto x, auto y) {
		return x.second < y.second;
	});


	for (int i = 0; i < N; i++) {
		std::cout << ans[i] << "\n";
	}


	return 0;
}