#include <bits/stdc++.h>

using namespace std;

int n;
map <string, int> mp;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		string s;
		cin >> s;

		if (mp.count (s)) {
			cout << s;
			cout << "(" << mp[s] << ")" << "\n";
		} else {
			cout << s << "\n";;
		}

		mp[s] ++ ;
	}
	
	return 0;
}