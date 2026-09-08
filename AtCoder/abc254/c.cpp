#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i ++ ) {
		vector <int> b;
		for (int j = i; j < n; j += m) {
			b.push_back (a[j]);
		}
		
		sort (b.begin (), b.end ());

		for (int j = i; j < n; j += m) {
			a[j] = b[(j - i) / m];
		}
	}

	if (is_sorted (a.begin (), a.end ())) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}

	return 0;
}