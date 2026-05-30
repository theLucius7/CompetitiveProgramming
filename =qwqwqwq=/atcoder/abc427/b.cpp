#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	a[0] = 1;

	int sum = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = sum;
		int x = a[i];
		while (x) {
			sum += x % 10;
			x /= 10;
		}
	}

	std::cout << a[n] << "\n";

	return 0;
}