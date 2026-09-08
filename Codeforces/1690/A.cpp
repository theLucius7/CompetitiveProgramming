#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		int h1 = (n + 5) / 3;

		int h2 = min (h1 - 1, n - h1 - 1);

		int h3 = n - h1 - h2;

		cout << h2 << " " << h1 << " " << h3 << "\n";

	}

	return 0;
}