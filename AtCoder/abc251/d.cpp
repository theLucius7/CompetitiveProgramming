#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int w;
	cin >> w;

	int n = 297;
	cout << n << "\n";

	for (int i = 1; i <= 99; i ++ ) {
		cout << i << " ";
	}

	for (int i = 1; i <= 99; i ++ ) {
		cout << i * 100 << " ";
	}

	for (int i = 1; i <= 99; i ++ ) {
		cout << i * 10000 << " \n"[i == 99];
	}

	return 0;
}