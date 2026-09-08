#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	vector <int> st(26);
	for (int i = 0; i < s.size (); i ++ ) {
		st[s[i] - 'a'] ++ ;
	}
	
	for (int i = 0; i < 26; i ++ ) {
		if (st[i] == 1) {
			cout << char (i + 'a');
			return 0;
		}
	}
	cout << -1;
	
	return 0;	
}