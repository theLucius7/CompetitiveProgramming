#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string a, b;
	std::cin >> a >> b;

	std::swap(a[0], b[0]);

	std::cout << a << " " << b << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}