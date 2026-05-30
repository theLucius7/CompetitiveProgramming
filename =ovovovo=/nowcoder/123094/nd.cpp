#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

    auto cmp = [&](std::pair<int, int> a, std::pair<int, int> b) {
        return a.second < b.first;
    };
    std::set<std::pair<int, int>, decltype(cmp)> set(cmp);

	for (int i = 0; i < n; i++) {
		char op;
		std::cin >> op;

		if (op == 'A') {
            int l, r;
            std::cin >> l >> r;

            auto it = set.find({l, r});
            int cnt = 0;
            while (it != set.end()) {
                cnt++;
                set.erase(it);
                it = set.find({l, r});
            }
            std::cout << cnt << "\n";
            set.insert({l, r});
		} else {
			std::cout << set.size() << "\n";
		}
	}


	return 0;
}