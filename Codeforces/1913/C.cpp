#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m;
	std::cin >> m;

	std::vector<int> cnt(32);
	while (m--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int v;
			std::cin >> v;
			cnt[v]++;
		} else {
			int t;
			std::cin >> t;
			bool ok = true;
			auto ncnt = cnt;
			for (int i = 31; i >= 0; i--) {
				if ((t >> i) & 1) {
					int cur = 1;
					for (int j = i; j >= 0 && cur > 0; j--, cur *= 2) {
						int min = std::min(ncnt[j], cur);
						ncnt[j] -= min;
						cur -= min;
					}

					if (cur) {
						ok = false;
						break;
					}
				}
			}
			std::cout << (ok ? "YES" : "NO") << "\n";
		}
	}

	return 0;
}