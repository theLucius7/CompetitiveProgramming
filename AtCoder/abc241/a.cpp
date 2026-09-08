#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector <int> a(10);
	for (int i = 0; i < 10; i ++ ) {
		cin >> a[i];
	}

	int x = 0;
	for (int i = 0; i < 3; i ++ ) {
		x = a[x];
	}

	cout << x << "\n";


	return 0;
}