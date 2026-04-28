#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::vector<i64> pre(N + 1);
	for (int i = 0; i < N; i++) {
		pre[i + 1] = pre[i] + A[i];
	}

	int off = 0;
	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int c;
			std::cin >> c;
			off += c;
			off = (off + N) % N;
		} else {
			int l, r;
			std::cin >> l >> r;
			l--;
			r--;
			l = (l + off + N) % N;
			r = (r + off + N) % N;
			if (l <= r) {
				std::cout << pre[r + 1] - pre[l] << "\n";	
			} else {
				std::cout << pre[N] - pre[l] + pre[r + 1] << "\n";
			}		
		}
	}

	return 0;
}