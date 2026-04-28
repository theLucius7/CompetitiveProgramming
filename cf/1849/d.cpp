#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;


	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> r(n);
	std::iota(r.begin(), r.end(), 0);

	std::vector<int> lst(n, 0), nxt(n, n - 1);
	for (int i = 0; i < n - 1; i++) {
		lst[i + 1] = a[i] == 0 ? i : lst[i];
	}

	for (int i = n - 1; i > 0; i--) {
		nxt[i - 1] = a[i] == 0 ? i : nxt[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			r[lst[i]] = std::max(r[lst[i]], i);
			r[i] = std::max(r[i], r[nxt[i]]);
		} else if (a[i] == 2) {
			r[lst[i]] = std::max(r[lst[i]], nxt[i]);
		}
	}

	for (int i = 1; i < n; i++) {
		r[i] = std::max(r[i], r[i - 1]);
	}

	int ans = 0;
	for (int i = 0; i < n; i = r[i] + 1) {
		ans++;
	}

	std::cout << ans << "\n";

	return 0;
}