#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int P = 998244353;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> in(N), siz(N, 1);
	std::iota(in.begin(), in.end(), 0);

	int cnt = 0;
	while (Q--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			int P, H;
			std::cin >> P >> H;
			P--, H--;

			if (siz[in[P]] > 1) {
				cnt--;
			}
			siz[in[P]]--;
			if (siz[in[P]] > 1) {
				cnt++;
			}
			in[P] = H;
			if (siz[in[P]] > 1) {
				cnt--;
			}
			siz[in[P]]++;
			if (siz[in[P]] > 1) {
				cnt++;
			}
		} else {
			std::cout << cnt << "\n";
		}
	}


	return 0;
}