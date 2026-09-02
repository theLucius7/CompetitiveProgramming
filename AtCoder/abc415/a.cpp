#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<bool> st(101, false);
	for (int i = 0; i < N; i++) {
		int A;
		std::cin >> A;

		st[A] = true;
	}

	int X;
	std::cin >> X;

	std::cout << (st[X] ? "Yes" : "No") << "\n";

	return 0;
}