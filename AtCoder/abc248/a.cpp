#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	char a = 1;
	
	string s;
	cin >> s;
	
	for (char c : s) {
		a ^= c;
	}	
	
	cout << a << "\n";
	
	return 0;
}