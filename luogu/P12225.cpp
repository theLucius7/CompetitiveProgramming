#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::deque<i64> q1, q2;
	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		while (!q1.empty() && a[i] >= a[q1.back()]) {
			q1.pop_back();
		}
		q1.push_back(i);
		if (i - q1.front() + 1 > k) {
			q1.pop_front();
		}
		if (i >= k - 1) {
			sum += a[q1.front()];
		}


		while (!q2.empty() && a[i] <= a[q2.back()]) {
			q2.pop_back();
		}
		q2.push_back(i);
		if (i - q2.front() + 1 > k) {
			q2.pop_front();
		}
		if (i >= k - 1) {
			sum -= a[q2.front()];
		}
	}
	std::cout << std::fixed << std::setprecision(2) << sum * 1.0 / (n - k + 1) << "\n";


	return 0;
}