#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n, m;
		cin >> n >> m;

		if (m < n) {
			cout << "No\n";
			continue;
		}


		if (n % 2 == 1) {
			cout << "Yes\n";
			for (int i = 0; i < n - 1; i ++ ) {
				cout << "1 ";
			}
			cout << m - n + 1 << "\n";
			
		} else {
			int p = m - n + 2;
			if (p % 2 == 1) {
				cout << "No\n";
				continue;
			}

			cout << "Yes\n";

			for (int i = 0; i < n - 2; i ++ ) {
				cout << "1 ";
			}

			cout << p / 2 << " " << p / 2 << "\n";
		}
	}

	return 0;
}