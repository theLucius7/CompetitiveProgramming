#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	string s;
	cin >> s;

	int x = 0, y = 0;
	for (int i = 0; i < n; i ++ ) {
		if (s[i] == 'a') {
			if (x < a + b) {
				x ++ ;
				cout << "Yes" << "\n";
			} else {
				cout << "No" << "\n";
			}
		} else if (s[i] == 'b') {
			if (x < a + b && y < b) {
				x ++ , y ++ ;
				cout << "Yes" << "\n";
			} else {
				cout << "No" << "\n";
			}
		} else {
			cout << "No" << "\n";
		}
	}


	return 0;
}