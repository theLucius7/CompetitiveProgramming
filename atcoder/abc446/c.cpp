#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N, D;
	std::cin >> N >> D;

	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}

	std::deque<std::pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		q.emplace_back(i, A[i]);

		for ( ; ; ) {
			auto [id, cnt] = q.front();
			q.pop_front();
			if (B[i] < cnt) {
				cnt -= B[i];
				q.emplace_front(id, cnt);
				break;
			} else if (B[i] == cnt) {
				break;
			} else {
				B[i] -= cnt;
			}
		}

		for ( ; !q.empty(); ) {
			auto [id, cnt] = q.front();
			if (id <= i - D) {
				q.pop_front();
			} else {
				break;
			}
		}
	}

	int sum = 0;
	for (auto [id, cnt] : q) {
		sum += cnt;
	}
	std::cout << sum << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}