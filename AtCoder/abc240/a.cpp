#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	if ((a == 1 && b == 10) || (a + 1 == b) ) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}

	return 0;
}