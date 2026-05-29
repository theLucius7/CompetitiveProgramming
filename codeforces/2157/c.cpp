#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
	int n, k, Q;
	std::cin >> n >> k >> Q;

	std::vector<bool> flag1(n), flag2(n);
	std::vector<std::array<int, 3>> q(Q);
	for (int i = 0; i < Q; i++) {
		int c, l, r;
		std::cin >> c >> l >> r;
		l--, r--;
		q[i] = {c, l, r};


		if (c == 1) {
			for (int i = l; i <= r; i++) {
				flag1[i] = true;
			}	
		} else {
			for (int i = l; i <= r; i++) {
				flag2[i] = true;
			}
		}
		
	}

	int cur = 0;
	std::vector<int> a(n, inf);
	for (int i = 0; i < n; i++) {
		if (!flag1[i]) {
			a[i] = cur % k;
			cur++;
		}
	}

	for (auto [c, l, r] : q) {
		if (c == 1) {
			int x;
			for (int i = l; i <= r; i++) {
				if (!flag2[i]) {
					x = i;
					break;
				}
			}
			a[x] = k;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
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