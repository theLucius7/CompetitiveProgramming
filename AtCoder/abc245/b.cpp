#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		if (x < n) {
			a[x] ++ ;
		}
	}

	int ans = 0;
	while (a[ans]) {
		ans ++ ;
	}

	cout << ans << "\n";

	return 0;
}