#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	string t;
	while (t.length () != 6) {
		t += s;
	}
	
	cout << t << "\n";
	
	return 0;
}