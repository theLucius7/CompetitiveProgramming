#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 a, b;
	std::cin >> a >> b;

	std::vector<int> cnt(2);

	i128 x = 1;
	for (int i = 1; i <= 64; i++) {
		x *= 2;
		if ((i128)b / x * x < a) {
			break;
		}
		cnt[0]++;
	}
	x = 1;
	for (int i = 1; i <= 30; i++) {
		x *= 5;
		if ((i128)b / x * x < a) {
			break;
		}
		cnt[1]++;
	}

	std::cout << *min_element(cnt.begin(), cnt.end()) << "\n";


	return 0;
}