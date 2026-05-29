#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> L(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i];
	}

	int ans = 0;
	for (int i = 0; i < (1 << N); i++) {
		long double sum = 0.5;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			long double nsum = sum;
			if ((i >> j) & 1) {
				nsum += L[j];
			} else {
				nsum -= L[j];
			}
			if (nsum * sum < 0) {
				cnt++;
			}
			sum = nsum;
		}
		ans = std::max(ans, cnt);
	}


	std::cout << ans << "\n";

	return 0;
}	