#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size (); i ++ ) {
		if (a[i] == b[i]) {
			cout << "0";
		} else {
			cout << "1";
		}
	}	

	cout << "\n";

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}