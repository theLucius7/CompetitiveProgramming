#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		int A;
		std::cin >> A;
		if (q.empty() || q.back().first != A) {
			q.push_back({A, 1});
		} else if (q.back().first == A) {
			q.back().second++;
			if (q.back().second == 4) {
				q.pop_back();
			}
		} else {
			q.push_back({A, 1});
		}
	}

	int sum = 0;
	for (auto [x, cnt] : q) {
		// std::cout << x << " " << cnt << "\n";
		sum += cnt;
	}
	std::cout << sum << "\n";


	return 0;
}