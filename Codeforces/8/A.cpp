#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string s;
	cin >> s;
	
	string a, b;
	cin >> a >> b;
	
	int p1, p2;
	bool ok1 = false, ok2 = false;
	
	p1 = s.find (a);
	p2 = s.find (b, p1 + a.size ());
	
	if (p1 != string::npos && p2 != string::npos) {
		ok1 = true;
	}
	
	reverse (s.begin (), s.end ());
	
	p1 = s.find (a);
	p2 = s.find (b, p1 + a.size ());
	
	if (p1 != string::npos && p2 != string::npos) {
		ok2 = true;
	}
	
	if (ok1 && ok2) {
		cout << "both\n";
	} else if (ok1 && !ok2) {
		cout << "forward\n";
	} else if (!ok1 && ok2) {
		cout << "backward\n";
	} else {
		cout << "fantasy\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}