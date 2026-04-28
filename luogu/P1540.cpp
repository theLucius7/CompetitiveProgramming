#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int M, N;
	std::cin >> M >> N;

	std::deque<int> v;
	std::unordered_map<int, bool> map;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int a;
		std::cin >> a;
		if (map[a]) {
			continue;
		}
		if (v.size() >= M) {
			map[v.front()] = false;
			v.pop_front();
		}
		v.push_back(a);
		map[a] = true;
		ans++;
	}
	std::cout << ans << "\n";

	return 0;
}