#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	multiset <int> a;
	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		a.insert (x);
	}

	for (int i = 0; i < m; i ++ ) {
		int x;
		cin >> x;
		if (a.find (x) == a.end ()) {
			cout << "No" << "\n";
			return 0;
		} else {
			a.erase (a.find (x));
		}
	}

	cout << "Yes" << "\n";


	return 0;
}