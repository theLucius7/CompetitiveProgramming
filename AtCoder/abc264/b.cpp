#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y;
	cin >> x >> y;

	if (x > 8) {
		x = 16 - x;
	}
	if (y > 8) {
		y = 16 - y;
	}

	bool ok = false;
	if (x == 1) {
		if (y >= 1 && y <= 8) {
			ok = true;
		}
	} else if (x == 2) {
		if (y == 1) {
			ok = true;
		}
	} else if (x == 3) {
		if (y != 2) {
			ok = true;
		}
	} else if (x == 4) {
		if (y == 1 || y == 3) {
			ok = true;
		}
	} else if (x == 5) {
		if (y != 2 && y != 4) {
			ok = true;
		}
	} else if (x == 6) {
		if (y == 1 || y == 3 || y == 5) {
			ok = true;
		}
	} else if (x == 7) {
		if (y != 2 && y != 4 && y != 6) {
			ok = true;
		}
	} else if (x == 8) {
		if (y == 1 || y == 3 || y == 5 || y == 7) {
			ok = true;
		}
	}
	

	if (ok) {
		cout << "black\n";
	} else {
		cout << "white\n";
	}

	return 0;
}