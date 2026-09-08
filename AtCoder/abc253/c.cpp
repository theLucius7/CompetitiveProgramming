#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	multiset <int> s;
	for (int i = 0; i < n; i ++ ) {
		int f;
		cin >> f;

		if (f == 1) {
			int x;
			cin >> x;
			s.insert (x);
		} else if (f == 2) {
			int a, b;
			cin >> a >> b;
			while (b -- && s.find (a) != s.end ()) {
				s.erase (s.find (a));
			}

		} else {
			cout << *s.rbegin () - *s.begin () << "\n";
		}
	}



	return 0;
}