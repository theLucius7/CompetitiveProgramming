#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	i64 sum = 0;
	int minn = 1E6 + 10;

	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < n; j ++ ) {
			int x;
			cin >> x;
			if ((i == 0 && j == n - 1) || (i == n - 1 && j == 0)) {
				minn = min (minn, x);
			}
			sum += x;
		}
	}

	if (n % 2 == 0) {
		cout << sum - minn << "\n";
	} else {
		cout << sum << "\n";
	}

	return 0;
}