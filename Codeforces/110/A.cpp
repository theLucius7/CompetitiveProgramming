#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string s;
	cin >> s;
	
	int cnt = 0;
	
	for (int i = 0; i < s.size (); i ++ ) {
		int x = s[i] - '0';
		if (x == 7 || x == 4) {
			cnt ++ ;
		}
	}
	
	if (cnt == 0) {
		cout << "NO\n";
		return;
	}
	
	while (cnt) {
		int x = cnt % 10;
		if (x != 4 && x != 7) {
			cout << "NO\n";
			return;
		}	
		cnt /= 10;
	} 
	
	cout << "YES\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 