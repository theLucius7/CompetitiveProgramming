#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void solve () {
	int n, m;
	cin >> n >> m;

	if (n <= 3 && m <= 3) {
		cout << (n + 1) / 2 << " " << (m + 1) / 2 << "\n";
		return;
	}

	cout << n << " " << m << "\n";
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