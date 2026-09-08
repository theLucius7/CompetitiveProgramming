#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	unordered_map <char, int> mp;
	mp['T'] = 1, mp['i'] = 2, mp['m'] = 3, mp['u'] = 4, mp['r'] = 5;

	while (T -- ) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		sort (s.begin (), s.end ());

		if (s == "Timru") {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}