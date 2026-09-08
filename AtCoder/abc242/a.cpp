#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, x;
	cin >> a >> b >> c >> x;

	if (x <= a) {
		cout << 1 << "\n";
	} 
	else if (x > b) {
		cout << 0 << "\n";
	}
	else {
		cout << fixed << setprecision (10) << 1.0 * c / (b - a) << "\n";
	}

	return 0;
}
