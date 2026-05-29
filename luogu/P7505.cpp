#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	i64 k;
	std::cin >> n >> m >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	std::deque<int> q;
	for (int i = 0; i < n; i++) {
		q.push_back(a[i]);
	}

	i64 l = -k, r = k;
	int cnt = n;
	while (!q.empty() && q.back() > r) {
		q.pop_back();
		cnt--;
	}
	while (!q.empty() && q.front() < l) {
		q.pop_front();
		cnt--;
	}

	while (m--) {
		int op;
		std::cin >> op;

		if (op == 1) {
			i64 x;
			std::cin >> x;
			l -= x;
			r -= x;
			while (!q.empty() && q.back() > r) {
				q.pop_back();
				cnt--;
			}
		} else if (op == 2) {
			i64 x;
			std::cin >> x;
			l += x;
			r += x;
			while (!q.empty() && q.front() < l) {
				q.pop_front();
				cnt--;
			}
		} else {
			std::cout << cnt << "\n";
		}
	}

	return 0;
}