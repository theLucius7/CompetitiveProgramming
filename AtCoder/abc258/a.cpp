#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int h = n / 60, mins = n % 60;
	cout << (21 + h) << ":";
	if (mins < 10) {
		cout << 0 << mins;
	} else {
		cout << mins;
	}

	return 0;
}