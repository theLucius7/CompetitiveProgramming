#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector <int> a;
	for (int i = 0; i < s.size (); i ++ ) {
		if (s[i] == '1') {
			a.push_back (i);
		}
	}

	if (a.size () <= 2) {
		cout << "YES\n";
	} else {
		int d = a[1] - a[0];
		for (int i = 2; i < a.size (); i ++ ) {
			if (a[i] - a[i - 1] != d) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	}
	
}

int main () {
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);


	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}