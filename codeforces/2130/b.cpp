#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 s;
	std::cin >> n >> s;

	std::vector<int> a(n);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] == 1) {
			cnt1++;
		} else if (a[i] == 2) {
			cnt2++;
		}
	}
	int cnt0 = n - cnt1 - cnt2;

	std::sort(a.begin(), a.end());
	i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
	if (sum > s) {
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " \n"[i == n - 1];
		}
	} else if (sum + 1 == s) {
		for (int i = 0; i < cnt0; i++) {
			std::cout << "0 ";
		}
		for (int i = 0; i < cnt2; i++) {
			std::cout << "2 ";
		}
		for (int i = 0; i < cnt1; i++) {
			std::cout << "1 ";
		}
		std::cout << "\n";
	} else {
		std::cout << "-1\n";
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