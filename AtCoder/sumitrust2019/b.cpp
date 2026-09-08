#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	cin >> x;

	for (int i = 1; i <= 50000; i ++ ) {
		if (x == floor (i * 1.08)) {
			cout << i << "\n";
			return 0;
		}
	}

	cout << ":(" << "\n";

	return 0;
}