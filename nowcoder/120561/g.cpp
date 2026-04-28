#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 l, r;
	std::cin >> l >> r;

	auto calc = [&](i64 x) {
		std::string s = std::to_string(x);
		std::reverse(s.begin(), s.end());
		return std::stoll(s);
	};

	i64 max = calc(r);

	i64 power = 10;
	while (true) {
		i64 x = r / power * power - 1;
		if (x < l) {
			break;
		}
		max = std::max(max, calc(x));
		power *= 10;
	}

	std::cout << max << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}