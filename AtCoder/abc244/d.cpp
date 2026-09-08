#include <bits/stdc++.h>

using namespace std;

bool check (string s) {
	return s == "G R B" || s == "R B G" || s == "B G R";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s, t;
	getline (cin, s), getline (cin, t);
	
	if (check (s) == check (t)) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}
	
	return 0;
}