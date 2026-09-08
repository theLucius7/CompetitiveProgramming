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

		vector <int> s(n), f(n);
		for (int i = 0; i < n; i ++ ) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i ++ ) {
			cin >> f[i];
		}

		for (int i = 0; i < n; i ++ ) {
			cout << f[i] - max (i == 0 ? 0 : f[i - 1], s[i]) << " \n"[i == n - 1];
		}
	}


	return 0;
}