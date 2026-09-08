#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	for (int i = 1; i <= 35; i ++ ) {
		if (i * (i + 1) / 2== n) {
			cout << "YES\n";
			return;
		}
	}	

	cout << "NO\n";

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}