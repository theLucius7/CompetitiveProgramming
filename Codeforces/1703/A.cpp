#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		string a;
		cin >> a;

		if ((a[0] == 'Y' || a[0] == 'y') && (a[1] == 'E' || a[1] == 'e') && (a[2] == 'S' || a[2] == 's')) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}