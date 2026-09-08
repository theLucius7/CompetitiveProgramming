#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	cout << (n + 1) / 2 << "\n";

	for (int i = 1; i <= n / 2; i ++ ) {
		cout << i * 3 - 2 << " " << (n - i + 1) * 3 << "\n";
	}

	if (n & 1) {
		cout << (n + 1) / 2 * 3 - 2 << " " << (n + 1) / 2 * 3 << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		solve ();
	}

	return 0;
}