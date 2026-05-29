#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long


signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	
	std::map<int, std::vector<int>> id;
	for (int i = 0; i < N; i++) {
		int A;
		std::cin >> A;
		id[A].push_back(i + 1);
	}

	int ans = -1;
	for (auto [k, v] : id) {
		if (v.size() == 1) {
			ans = v[0];
		}
	}
	std::cout << ans << "\n";

	return 0;
}