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

	std::vector<int> l(n), r(n);
	std::vector<int> q;
	for (int i = 0; i < n; i++) {
		while (!q.empty() && a[i] <= a[q.back()]) {
			q.pop_back();
		}
		if (!q.empty()) {
			l[i] = q.back();
		} else {
			l[i] = -1;
		}
		q.push_back(i);
	}
	q.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!q.empty() && a[i] <= a[q.back()]) {
			q.pop_back();
		}
		if (!q.empty()) {
			r[i] = q.back();
		} else {
			r[i] = n;
		}
		q.push_back(i);
	}

	i64 max = 0;
	for (int i = 0; i < n; i++) {
		max = std::max(max, 1LL * (r[i] - l[i] - 1) * a[i]);
	}
	std::cout << max << "\n";

	return 0;
}