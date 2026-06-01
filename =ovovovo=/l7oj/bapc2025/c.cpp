#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

constexpr int inf = 1E8;

void solve() {
	std::string S;
	std::cin >> S;
	for (int i = 1; i <= S.size() / 2; i++) {
		std::string x = S.substr(0, i), y = S.substr(i);
		int a = std::stoi(x), b = std::stoi(y);
		std::string sa = std::to_string(a), sb = std::to_string(b);
		// std::cout << a << " " << b << "\n";
		if (a < b && sa.size() == i && sb.size() == S.size() - i) {
			std::cout << a << " " << b << "\n";
			return;
		} 
	}
	std::cout << -1 << "\n";
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