#include <bits/stdc++.h>

using i64 = long long;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, L, R;
	std::cin >> N >> L >> R;

	int ans = 0;
	int X, Y;
	for (int i = 0; i < N; i++) {
		std::cin >> X >> Y;
		if (X <= L && R <= Y) {
			ans++;
		}
	}
	std::cout << ans << "\n";


	return 0;
}