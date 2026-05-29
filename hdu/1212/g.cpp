#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n),b(n),c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	// i64 sum = std::accumulate(a.begin(), a.end(), 0);
	i64 max = -LLONG_MAX;
	std::vector<int> sl(n + 1), sr(n + 1);
	for (int i = 0; i < n; i++) {
		sl[i + 1] = sl[i] + a[i];
	}
	for (int i = 0; i < n; i++) {
		
	}
	for(int i = 0 ; i < n ; i++{

	})
	for (int i = 2; i < n - 2; i++) {
		max = std::max(max, a[i]);
	}
	std::cout << max << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T -- ) {
		solve();
	}

	return 0;
}