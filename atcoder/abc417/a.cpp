#include <bits/stdc++.h>

using i64 = long long;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, A, B;
	std::cin >> N >> A >> B;

	std::string S;
	std::cin >> S;

	for (int i = A; i < N - B; i++) {
		std::cout << S[i];
	}
	std::cout << "\n";

	return 0;
}