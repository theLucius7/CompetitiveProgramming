#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<i64> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::vector<i64> sum(N + 1);
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + A[i];
	}

	int cnt = 0;
	for (int l = 0; l < N; l++) {
		for (int r = l + 1; r < N; r++) {
			i64 s = sum[r + 1] - sum[l];
			bool ok = true;
			for (int i = l; i <= r; i++) {
				if ((s % A[i] == 0)) {
					ok = false;
					break;
				}
			}
			if (ok) {
				// std::cout << l + 1 << " " << r + 1 << "\n";
				cnt++;
			}
		}
	}

	std::cout << cnt << "\n";

	return 0;
}