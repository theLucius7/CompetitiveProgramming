#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N, S;
	std::cin >> N >> S;

	std::vector<int> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}

	for (int i = 0; i < N; i++) {
		if (T[i] - (i ? T[i - 1] : 0) > S) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}