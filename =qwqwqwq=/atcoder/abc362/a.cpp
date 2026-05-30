#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int R, G, B;
	std::cin >> R >> G >> B;

	std::map<std::string, int> mp;
	mp["Red"] = R;
	mp["Green"] = G;
	mp["Blue"] = B;

	std::string S;
	std::cin >> S;

	int min = inf;
	std::vector<std::string> v = {"Red", "Green", "Blue"};
	for (int i = 0; i < 3; i++) {
		if (v[i] != S) {
			min = std::min(min, mp[v[i]]);
		}
	}

	std::cout << min << "\n";


	return 0;
}