#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n),b(n),c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	vector<int> pre(n), suf(n);
	pre[0] = a[0];
	suf[n - 1] = a[n - 1];
	for (int i = 1; i < n; i ++ ) {
		pre[i] = max(a[i], a[i] + pre[i - 1]);
	}
	for (int i = 1; i < n; i ++ ) {
		pre[i] = max(pre[i], pre[i - 1]);
	}
	for (int i = n - 2; i >= 0; i -- ) {
		suf[i] = max(a[i], a[i] + suf[i + 1]);
	}
	for (int i = n - 2; i >= 0; i -- ) {
		suf[i] = max(suf[i], suf[i + 1]);
	}
	vector<int> f(n, -inf);
	for (int i = 2; i + 2 < n; i ++ ) {
		f[i] = a[i] + pre[i - 2] + suf[i + 2];
	}
	cout << *max_element(f.begin(), f.end()) << endl;
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