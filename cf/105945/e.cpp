#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;
	vector<array<int, 2>> a(n);
	for (int i = 0; i < 2; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			cin >> a[j][i];
		}
	}
	// if (!a[0][0] && !a[0][1]) {
	// 	a[0][0] = 1;
	// 	a[0][1] = 2;
	// } else if (!a[0][0]) {
	// 	a[0][0] = a[0][1] == 1 ? 2 : 1;
	// } else if (!a[0][1]) {
	// 	a[0][1] = a[0][0] == 1 ? 2 : 1;
	// }
	for (int i = 0; i < n; i ++ ) {
		if (!a[i][0] && !a[i][1]) {
			a[i][0] = 1;
			a[i][1] = 2;
		} else if (!a[i][0]) {
			a[i][0] = a[i][1] == 1 ? 2 : 1;
		} else if (!a[i][1]) {
			a[i][1] = a[i][0] == 1 ? 2 : 1;
		}
	}
	for (int i = 0; i < 2; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			cout << a[j][i] << " \n"[j == n - 1];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}