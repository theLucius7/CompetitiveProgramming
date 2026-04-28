#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int l, r;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	cin >> l >> r;

	int maxv = 0;
	for (int i = 0; i < n; i ++ ) {
		if (a[i] >= l && a[i] <= r) {
			maxv = max (maxv, a[i]);
		}
	}

	cout << maxv + r << "\n";

	return 0;
}