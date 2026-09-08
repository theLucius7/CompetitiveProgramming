#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <vector <int>> a(n, vector <int> (3));
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i][1] >> a[i][0];
	}

	string s;
	cin >> s;
	for (int i = 0; i < n; i ++ ) {
		a[i][2] = (s[i] == 'R');
	}

	sort (a.begin (), a.end ());

	for (int i = 0; i < n; i ++ ) {
		int j = i;
		while (j < n && a[i][0] == a[j][0]) j ++ ;

		for (int k = i; k + 1 < j; k ++ ) {
			if (a[k][2] == 1 && a[k + 1][2] == 0) {
				cout << "Yes" << "\n";
				return 0;
			}
		}

		i = j - 1;
	}

	cout << "No" << "\n";


	return 0;
}