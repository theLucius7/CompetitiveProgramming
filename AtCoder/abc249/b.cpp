#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	bool st[N];
	memset (st, false, sizeof st);
	
	bool test1 = true, test2 = false, test3 = false;
	for (int i = 0; i < s.size (); i ++ ) {
		if (st[(int)s[i]]) {
			test1 = false;
		} else {
			st[(int)s[i]] = true;
			if (s[i] >= 'a' && s[i] <= 'z') test2 = true;
			else if (s[i] >= 'A' && s[i] <= 'Z') test3 = true;
		}
	}
	
	if (test1 && test2 && test3) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}