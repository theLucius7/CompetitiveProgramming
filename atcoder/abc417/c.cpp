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
	}

	std::vector<int> cnt(N + *max_element(A.begin(), A.end()));
	i64 ans = 0;
	for (int i = 0; i < N; i++) {
		if (i - A[i] >= 0) {
			ans += cnt[i - A[i]];
		}
		cnt[i + A[i]]++;
	}
	std::cout << ans << "\n";


	return 0;
}