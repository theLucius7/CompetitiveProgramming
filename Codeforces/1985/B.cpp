#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int ans = -1, AnsSum = 0;
	for (int i = 2; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j * i <= n; j++) {
			sum += j * i;
		}
		if (sum > AnsSum) {
			ans = i;
			AnsSum = sum;
		}
	}

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}