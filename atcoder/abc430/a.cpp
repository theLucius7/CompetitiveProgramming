#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int A, B, C, D;
	std::cin >> A >> B >> C >> D;

	if (C >= A && D < B) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}

	return 0;
}