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

	int K;
	std::cin >> K;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= K) {
			ans++;
		}
	}
	std::cout << ans << "\n";

	return 0;
}