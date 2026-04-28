#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> m >> n;

	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<std::vector<int>> b(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> b[i][j];
		}
	}

	std::vector<long double> r(n);
	for (int i = 0; i < n; i++) {
		long double avg = std::accumulate(a[i].begin(), a[i].end(), (long double)0) / m;
		for (int j = 0; j < m; j++) {
			r[i] += ((long double)a[i][j] - avg) * ((long double)a[i][j] - avg) / m;
		}
	}
	for (int i = 0; i < n; i++) {
		long double avg = std::accumulate(b[i].begin(), b[i].end(), (long double)0) / m;
		for (int j = 0; j < m; j++) {
			r[i] += ((long double)b[i][j] - avg) * ((long double)b[i][j] - avg) / m;
		}
	}


	std::vector<std::pair<int, int>> ans;
	for (int i = 0; i < n - 1; i++) {
		std::pair<long double, int> min{r[i], i};
		for (int j = i + 1; j < n; j++) {
			if (r[j] < min.first) {
				min.first = r[j];
				min.second = j;
			}
		}
		if (min.second != i) {
			ans.emplace_back(i + 1, min.second + 1);
			std::swap(r[i], r[min.second]);
		}
	}

	std::cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}