#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < n; i ++ ) {
		for (int j = 0; j < a; j ++ ) {
			for (int k = 0; k < n; k ++ ) {
				for (int l = 0; l < b; l ++ ) {
					if ((i + k) % 2 == 0) {
						cout << '.';
					} else {
						cout << '#';
					}
				}				
			}
			cout << "\n";
		}
	}

	return 0;
}