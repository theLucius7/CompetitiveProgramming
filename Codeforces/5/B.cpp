#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string p;
	vector <string> s;
	
	int n = 0;
	
	while (getline (cin, p)) {
		s.push_back (p); 
		n = max (n, (int)p.size ());
	}
	
	for (int i = 0; i < n + 3; i ++ ) {
		cout << "*\n"[i == n + 2];
	}	

	int cnt = 1;
	for (int i = 0; i < s.size (); i ++ ) {
		cout << "*";
		
		if ((n - s[i].size ()) / 2 != n - (n - s[i].size ()) / 2 - s[i].size ()) {
			cnt ++ ;
		}
		
		if (cnt % 2 == 0) {
			for (int j = 0; j < (n - s[i].size ()) / 2; j ++ ) {
				cout << " ";
			}
			cout << s[i];
			for (int j = 0; j < n - (n - s[i].size ()) / 2 - s[i].size (); j ++ ) {
				cout << " ";
			}
		} else {
			for (int j = 0; j < n - (n - s[i].size ()) / 2 - s[i].size (); j ++ ) {
				cout << " ";
			}
			cout << s[i];
			for (int j = 0; j < (n - s[i].size ()) / 2; j ++ ) {
				cout << " ";
			}
		}
				
		cout << "*\n";
	}
	
	for (int i = 0; i < n + 3; i ++ ) {
		cout << "*\n"[i == n + 2];
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}