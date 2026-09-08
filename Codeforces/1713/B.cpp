#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		bool ok1 = true, ok2 = true;

		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
			if (i != 0) {
				if (a[i] > a[i - 1] + 1) {
					ok1 = false;
				}
				if (a[i] < a[i - 1] - 1) {
					ok2 = false;
				}
			}
		}

		if (ok1 || ok2) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}