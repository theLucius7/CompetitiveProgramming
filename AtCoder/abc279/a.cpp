#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int cnt = 0;

	for (int i = 0; i < s.size (); i ++ ) {
		if (s[i] == 'v') {
			cnt ++ ;
		} else {
			cnt += 2;
		}
	}

	cout << cnt << "\n";

	return 0;
}