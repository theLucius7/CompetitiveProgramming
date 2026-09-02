#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::unordered_map<int, int> f;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int A;
		std::cin >> A;
		f[A] = std::max(f[A], f[A - 1] + 1);
		ans = std::max(ans, f[A]);
	}
	std::cout << ans << "\n";

	return 0;
}