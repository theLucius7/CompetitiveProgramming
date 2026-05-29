#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, K;
	std::cin >> N >> M >> K;

	std::vector<int> H(N);
	for (int i = 0; i < N; i++) {
		std::cin >> H[i];
	}
	std::vector<int> B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> B[i];
	}

	std::sort(H.begin(), H.end());
	std::sort(B.begin(), B.end());

	int cnt = 0;
	int i = 0, j = 0;
	for ( ; i < N && j < M; ) {
		if (H[i] <= B[j]) {
			cnt++;
			i++, j++;
		} else {
			j++;
		}
	}

	std::cout << (cnt >= K ? "Yes" : "No") << "\n";

	return 0;
}