#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<std::pair<int, int>> A = {{1600, 2999}, {1200, 2399}};

	int R, X;
	std::cin >> R >> X;

	std::cout << (((A[X - 1].first <= R) && (R <= A[X - 1].second)) ? "Yes" : "No") << "\n"; 
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}