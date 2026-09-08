#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;

	cout << '0' + s.substr(0, 3) << "\n";	
	return 0;
}