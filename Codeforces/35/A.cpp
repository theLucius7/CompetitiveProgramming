#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int x;
	cin >> x;

	for (int i = 0; i < 3; i ++ ) {
		int a, b;
		cin >> a >> b;

		if (x == a) {
			x = b;
		} else if (x == b) {
			x = a;
		}
	}

	cout << x << "\n";
}

int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}