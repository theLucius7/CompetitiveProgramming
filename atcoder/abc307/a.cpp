#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int ans = 0;
		for (int j = 0; j < 7; j++) {
			int A;
			std::cin >> A;
			ans += A;
		}
		std::cout << ans << " ";
	}

	return 0;
}