#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::vector<int> v;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '#') {
			v.push_back(i + 1);
		}
	}

	for (int i = 0; i < v.size(); i += 2) {
		std::cout << v[i] << "," << v[i + 1] << "\n";
	}

	return 0;
}