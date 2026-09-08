#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string s, p;
	cin >> s >> p;

	reverse (s.begin (), s.end ());

	if (s == p) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}