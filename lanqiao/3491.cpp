#include <bits/stdc++.h>

using i64 = long long;

bool isGood(int x) {
	std::string s = std::to_string(x);
	if (s.size() & 1) {
		return false;
	}

	int a = 0, b = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		a += (s[i] - '0');
		b += (s[s.size() - 1 - i] - '0');
	}
	return a == b;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << 4430091 << "\n";
	return 0;

	int ans = 0;
	for (int i = 1; i <= 1E8; i++) {
		if (isGood(i)) {
			ans++;
		}
	}
	std::cout << ans << "\n";

	return 0;
}