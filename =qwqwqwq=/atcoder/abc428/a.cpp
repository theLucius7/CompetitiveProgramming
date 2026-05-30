#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int S, A, B, X;
	std::cin >> S >> A >> B >> X;

	int cnt = X / (A + B), d = X % (A + B);
	std::cout << std::min(A, d) * S + cnt * A * S << "\n";

	return 0;
}