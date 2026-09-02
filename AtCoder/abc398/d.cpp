#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long


signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, R, C;
	std::cin >> N >> R >> C;

	std::string s;
	std::cin >> s;

	int x = 0, y = 0;
	std::set<std::pair<int, int>> set;
	set.insert({x, y});
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'N') {
			x++;
			R++;
		} else if (s[i] == 'S') {
			x--;
			R--;
		} else if (s[i] == 'W') {
			y++;
			C++;
		} else {
			y--;
			C--;
		}

		set.insert({x, y});

		if (set.find({R, C}) != set.end()) {
			std::cout << "1";
		} else {
			std::cout << "0";
		}
	}
	std::cout << "\n";

	return 0;
}