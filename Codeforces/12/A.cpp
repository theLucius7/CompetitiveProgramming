#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	vector <string> s(3);
	for (int i = 0; i < 3; i ++ ) {
		cin >> s[i];
	}
	
	for (int i = 0; i < 3; i ++ ) {
		for (int j = 0; j < 3; j ++ ) {
			if (s[i][j] != s[2 - i][2 - j]) {
				cout << "No\n";
				return;
			}
		} 
	}
	
	cout << "Yes\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}