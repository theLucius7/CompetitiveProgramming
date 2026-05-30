#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::set<int> set;
	for (int i = 0; i < N; i++) {
		int x;
		std::cin >> x;
		set.insert(x);
	}

	std::cout << set.size() << "\n";
	for (auto x : set) {
		std::cout << x << " ";
	}

	return 0;
}
