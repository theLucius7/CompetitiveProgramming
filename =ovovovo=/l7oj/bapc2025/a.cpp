#include <bits/stdc++.h>

using i64 = long long;

#define int long long

constexpr int inf = 1E18;

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::set<int, int, int> sl, sr;
	for (int i = 0; i < M; i++) {
		int L, R;
		std::cin >> L >> R;
		sl.insert({L, R, i});
		sr.insert({})
	}

	return 0;
}