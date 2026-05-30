#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N;
	std::cin >> N;

	std::string T, A;
	std::cin >> T >> A;

	for (int i = 0; i < N; i++) {
		if (T[i] == 'o' && A[i] == 'o') {
			std::cout << "Yes\n";
			return;
		}
	}

	std::cout << "No\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}