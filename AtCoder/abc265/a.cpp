#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y, n;
	cin >> x >> y >> n;

	if (3 * x < y) {
		cout << n * x << "\n";
	} else {
		cout << (n % 3) * x + (n / 3) * y << "\n";
	}

	return 0;
}