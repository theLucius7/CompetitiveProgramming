#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int sum = 0;
	std::vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
		if (i == 0) {
			v.push_back(s[i] - '1');
		} else {
			v.push_back(s[i] - '0');
		}
	}

	std::sort(v.begin(), v.end(), std::greater<>());

	int res = 0;
	if (sum <= 9) {
		std::cout << 0 << "\n";
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		res += v[i];
		if (res >= sum - 9) {
			std::cout << i + 1 << "\n";
			break;
		}
	}	
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