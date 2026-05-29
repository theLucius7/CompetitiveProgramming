#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int Min = 1e9, Max = 0;
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		Min = min(Min, a[i]);
		Max = max(Max, a[i]);
	}
	cout << Max - Min + 1 << endl;
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