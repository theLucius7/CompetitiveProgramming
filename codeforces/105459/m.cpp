#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> d;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			d.push_back(i);
			if (n / i != i) {
				d.push_back(n / i);
			}
		}
	}
	std::sort(d.begin(), d.end());

	i64 sum = 1;
	int l = 0;
	for ( ; l < d.size() - 1; ) {
		sum += (d[l + 1] - d[l]) * (n / d[l]);
		l++;
	}
	std::cout << sum << "\n";
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