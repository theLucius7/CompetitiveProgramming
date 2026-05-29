#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> A(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> A[i];
	}

	std::sort(A.begin(), A.end());

	std::cout << (A[0] * A[1] == A[2] ? "Yes" : "No") << "\n";

	return 0;
}