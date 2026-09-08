#include <bits/stdc++.h>

using i64 = long long;

#define int long long

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string S;
	std::cin >> S;

	auto calc = [&](char x, char y) {
		std::vector<int> v(N);
		for (int i = 0; i < N; i++) {
			if (S[i] == x) {
				v[i] = 1;
			} else if (S[i] == y) {
				v[i] = -1;
			}
		}

		std::vector<int> sum(N + 1);
		std::map<int, int> cnt;
		cnt[0] = 1;
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + v[i];
			cnt[sum[i + 1]]++;
		}

		i64 res = 0;
		for (auto [k, v] : cnt) {
			res += v * (v - 1) / 2;
		}
		return res;
	};

	std::map<std::pair<int, int>, int> ss;
	ss[{0, 0}] = 1;
	i64 res = 0;
	std::vector<int> cnt(3);
	for (int i = 0; i < N; i++) {
		cnt[S[i] - 'A']++;
		std::pair<int, int> now = {cnt[0] - cnt[1], cnt[1] - cnt[2]};
		res += ss[now];
		ss[now]++;
	}


	std::cout << 1LL * N * (N + 1) / 2 - calc('A', 'B') - calc('B', 'C') - calc('A', 'C') + 2 * res << "\n";


	return 0;
}
