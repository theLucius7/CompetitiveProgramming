#include <bits/stdc++.h>

using namespace std;

string s[2];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		cin >> s[0] >> s[1];

		for (int i = 0; i < s[0].size (); i ++ ) {
			if (s[0][i] == 'G') {
				s[0][i] = 'B';
			}
		}

		for (int i = 0; i < s[1].size (); i ++ ) {
			if (s[1][i] == 'G') {
				s[1][i] = 'B';
			}
		}

		if (s[0] == s[1]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}