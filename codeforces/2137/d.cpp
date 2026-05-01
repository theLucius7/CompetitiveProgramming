#include <bits/stdc++.h>

using i64 = long long;

using i128 = __int128;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n);
	std::vector<int> cnt(n + 1);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		cnt[b[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] != 0 && cnt[i] % i != 0) {
			std::cout << -1 << "\n";
			return;
		}
	}

	std::vector<int> cnt2(n + 1);
	std::vector<int> id(n + 1);
	int cur = 1;
	for (int i = 0; i < n; i++) {
		if (!id[b[i]] || cnt2[id[b[i]]] == b[i]) {
			id[b[i]] = cur++;
		}
		cnt2[id[b[i]]]++;
		std::cout << id[b[i]] << " \n"[i == n - 1];
	}
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