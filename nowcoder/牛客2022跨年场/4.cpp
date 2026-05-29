#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	while (c % a == 0) {
		c /= a;
	}
	while (c % b == 0) {
		c /= b;
	}

	if (c == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}