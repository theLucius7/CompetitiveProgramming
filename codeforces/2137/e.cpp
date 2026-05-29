#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}


	k = std::min(k, k % 2 + 2);
	while (k--) {
		std::vector<int> cnt(n + 1);
		for (int i = 0; i < n; i++) {
			cnt[a[i]]++;
		}

		int mex = n + 1;
		for (int i = 0; i <= n; i++) {
			if (!cnt[i]) {
				mex = i;
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			if (cnt[a[i]] >= 2 || (cnt[a[i]] == 1 && a[i] >= mex)) {
				a[i] = mex;
			}
		}
	}
	std::cout << std::accumulate(a.begin(), a.end(), 0LL) << "\n";
	// for (int i = 0; i < a.size(); i++) {
	// 	std::cout << a[i] << " \n"[i == a.size() - 1];
	// }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}