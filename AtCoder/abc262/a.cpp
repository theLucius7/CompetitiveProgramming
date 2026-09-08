#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int k = n / 4, r = n % 4;

	if (r <= 2) {
		cout << 4 * k + 2 << "\n";
	} else {
		cout << 4 * k + 6 << "\n";
	}


	return 0;
}