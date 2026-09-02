#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int H, B;
	std::cin >> H >> B;

	std::cout << std::max(0, H - B) << "\n";

	return 0;
}