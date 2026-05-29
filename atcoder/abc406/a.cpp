#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int A, B, C, D;
	std::cin >> A >> B >> C >> D;

	std::cout << (((A * 60 + B) < (C * 60 + D)) ? "No" : "Yes") << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}