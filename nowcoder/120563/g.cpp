#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n), b(m);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	i64 suma = std::accumulate(a.begin(), a.end(), 0LL), sumb = std::accumulate(b.begin(), b.end(), 0LL);
	if (suma == sumb) {
		std::cout << "1\n";
		return;
	}

	if (suma > sumb) {
		int id = a.size() - 1;
		while (suma > sumb) {
			suma -= a[id];
			id--;
		}
		std::cout << a.size() - 1 - id << "\n";
	} else {
		int id = b.size() - 1;
		while (sumb > suma) {
			sumb -= b[id];
			id--;
		}
		std::cout << b.size() - 1 - id << "\n";
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