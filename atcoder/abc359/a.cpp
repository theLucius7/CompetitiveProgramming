#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		std::string S;
		std::cin >> S;
		ans += (S == "Takahashi");
	}
	std::cout << ans << "\n";

	return 0;
}