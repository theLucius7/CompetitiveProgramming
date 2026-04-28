#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}


	std::sort(a.begin(), a.end());


	i64 ans = 0, x = 0, cur = a[0];
	i64 s = -1;
	
	int i = 0;
	while (i < n || x > 0) {
		i64 cnt = 0;
		while (i < n && a[i] == cur) {
			cnt++;
			i++;
		}
		
		if (x + cnt <= k) {
			if (s != -1) {
				ans = std::max(ans, cur - s);
				s = -1;
			}
			x = 0;
			cur = (i < n ? a[i] : cur + 1);
		} else {
			if (s == -1) {
				s = cur;
			}
			x = x + cnt - 1;
			cur++;
		}
	}
	
	std::cout << ans << "\n";
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