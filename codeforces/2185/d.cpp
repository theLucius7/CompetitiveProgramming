#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, h;
	std::cin >> n >> m >> h;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::vector<int> A = a;
	int cnt = 0;
	std::vector<int> t(n);

	while (m--) {
		int b, c;
		std::cin >> b >> c;
		b--;

		if (t[b] < cnt) {
			a[b] = A[b] + c;
			t[b] = cnt;
		} else {
			a[b] = a[b] + c;
		}

		if (a[b] > h) {
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (t[i] < cnt) {
			a[i] = A[i];
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