#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N;
	std::cin >> N;

	std::string S;
	std::cin >> S;

	std::cout << (S[(1 << N) - 2] == '0' ? "Yes" : "No") << "\n";
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