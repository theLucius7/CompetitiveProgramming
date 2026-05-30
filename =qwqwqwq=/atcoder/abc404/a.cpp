#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string S;
	std::cin >> S;

	for (char c = 'a'; ; c++) {
		if (S.find(c) == -1) {
			std::cout << c << "\n";
			return;
		}
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}