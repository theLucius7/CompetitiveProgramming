#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	vector <string> s(8);
	for (int i = 0; i < 8; i ++ ) {
		cin >> s[i];
	}
	
	int ans = 0;
	
	for (int i = 0; i < 8; i ++ ) {
		bool r = true, c = true;
		for (int j = 0; j < 8; j ++ ) {
			if (s[i][j] == 'W') {
				c = false;
			}
			if (s[j][i] == 'W') {
				r = false;
			}
		}
		
		ans += r + c;
	}
	
	if (ans == 16) {
		cout << "8\n";
	} else {
		cout << ans << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}