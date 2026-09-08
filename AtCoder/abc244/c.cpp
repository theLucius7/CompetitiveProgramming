#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;

	vector <bool> a(2 * n + 2);
	while (1) {
		for (int i = 1; i <= 2 * n + 1; i ++ ) {
			if (!a[i]) {
				cout << i << "\n";
				a[i] = true;
				break;
			}
		}

		int x;
		cin >> x;
		if (x == 0) break;
		else a[x] = true;
	}

	return 0;
}