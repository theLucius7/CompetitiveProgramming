#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string a, b;
	cin >> a >> b;
	
	for (int i = 0; i < a.size (); i ++ ) {
		if (isupper (a[i])) {
			a[i] = tolower (a[i]);
		}
		if (isupper (b[i])) {
			b[i] = tolower (b[i]);
		}
	}
	
	
	if (a > b) {
		cout << "1\n";
	} else if (a < b) {
		cout << "-1\n";
	} else {
		cout << "0\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 