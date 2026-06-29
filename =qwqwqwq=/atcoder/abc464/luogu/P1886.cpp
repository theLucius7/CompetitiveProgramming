#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::deque<int> q1, q2;
	std::vector<int> max(n), min(n);
	for (int i = 0; i < n; i++) {
		while (!q1.empty() && a[i] >= a[q1.back()]) {
			q1.pop_back();
		}
		q1.push_back(i);
		if (i - q1.front() > k - 1) {
			q1.pop_front();
		}
		if (i >= k - 1) {
			max[i] = a[q1.front()];
		}


		while (!q2.empty() && a[i] <= a[q2.back()]) {
			q2.pop_back();
		}
		q2.push_back(i);
		if (i - q2.front() > k - 1) {
			q2.pop_front();
		}
		if (i >= k - 1) {
			min[i] = a[q2.front()];
		}
	}

	for (int i = k - 1; i < n; i++) {
		std::cout << min[i] << " \n"[i == n - 1];
	}
	for (int i = k - 1; i < n; i++) {
		std::cout << max[i] << " \n"[i == n - 1];
	}



	return 0;
}