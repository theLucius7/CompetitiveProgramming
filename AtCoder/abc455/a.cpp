#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int A, B, C;
	std::cin >> A >> B >> C;

	std::cout << (A != B && B == C ? "Yes" : "No") << "\n";
	

	return 0;
}
