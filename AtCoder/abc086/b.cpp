#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b;
	cin >> a >> b;

	string s = a + b;

	int x = stoi (s);
	for (int i = 1; i <= 10000; i ++ ) {
		if (i * i == x) {
			cout << "Yes" << "\n";
			return 0;
		}
	}

	cout << "No" << "\n";

	return 0;
}