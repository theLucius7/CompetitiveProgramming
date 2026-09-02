#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> A(N), B(N), C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}

	std::sort(A.begin(), A.end(), std::greater<>());
	std::sort(B.begin(), B.end(), std::greater<>());
	std::sort(C.begin(), C.end(), std::greater<>());

	auto get = [&](int i, int j, int k) {
		return A[i] * B[j] + B[j] * C[k] + C[k] * A[i];
	};

	using Item = std::array<int, 5>;
	std::priority_queue<Item> pq;
	pq.push({get(0, 0, 0), 0, 0, 0, 0});
	for (int i = 0; i < K; i++) {
		auto [v, x, y, z, t] = pq.top();
		pq.pop();

		if (i == K - 1) {
			std::cout << v << "\n";
			return 0;
		}

		if (t == 0 && x + 1 < N) {
			pq.push({get(x + 1, y, z), x + 1, y, z, 0});
		} 
		if (t <= 1 && y + 1 < N) {
			pq.push({get(x, y + 1, z), x, y + 1, z, 1});
		}
		if (t <= 2 && z + 1 < N) {
			pq.push({get(x, y, z + 1), x, y, z + 1, 2});
		}
	}


	return 0;
}