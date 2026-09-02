#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::vector<int> posA, posB;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			posA.push_back(i);
		} else {
			posB.push_back(i);
		}
	}

	auto calc = [&](std::vector<int> v) {
		if (v.size() <= 1) {
			return 0ll;
		}
		i64 res = 0;
		std::vector<int> p(v.size());
		for (int i = 0; i < v.size(); i++) {
			p[i] = v[i] - i;
		}
		int m = p[v.size() / 2];
		for (int i = 0; i < v.size(); i++) {
			res += std::abs(p[i] - m);
		}
		return res;
	};

	std::cout << std::min(calc(posA), calc(posB)) << "\n";
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