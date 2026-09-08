#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}

	int x = 1, cnt = 0;
	while (x != 2) {
		x = a[x];
		cnt ++ ;
		if (cnt == n + 1) {
			cout << "-1" << "\n";
			return 0;
		}
	}

	cout << cnt << "\n";

	return 0;
}