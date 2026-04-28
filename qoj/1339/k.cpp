#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
#define int long long
void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	std::vector<int> cnt(64);
	int max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		for (int j = 40; j >= 0; j--) {
			if (a[i] >> j) {
				cnt[j]++;
				max = std::max(max, cnt[j]);
				break;
			}
		}
	}
	std::cout << max << "\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}