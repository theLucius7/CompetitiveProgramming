#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::set<std::pair<int, int>> set;
	for (int i = 0; i < Q; i++) {
		int L, R;
		std::cin >> L >> R;

		auto it = set.lower_bound({L, -1});
		if (it != set.begin() && (*std::prev(it)).second >= L) {
			it--;
		}

		i64 sum = 0;
		while (it != set.end() && (*it).first <= R) {
			L = std::min(L, (*it).first);
			R = std::max(R, (*it).second);
			sum -= (*it).second - (*it).first + 1;
			it = set.erase(it);
		}
		set.insert({L, R});

		sum += R - L + 1;
		N -= sum;
		std::cout << N << "\n";
	}

	return 0;
}