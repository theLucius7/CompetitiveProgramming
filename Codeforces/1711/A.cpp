#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int p[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		if (n == 1) {
			cout << "1\n";
		} else {
			cout << 2 << " ";
			for (int i = 3; i <= n; i ++ ) {
				cout << i << " ";
			}
			cout << 1 << "\n";
		}
	}

	return 0;
}