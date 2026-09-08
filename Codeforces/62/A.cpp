#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	array <int, 2> b, g;
	cin >> g[0] >> g[1] >> b[0] >> b[1];

	if ((b[0] >= g[1] - 1 && g[1] * 2 + 2 >= b[0]) || (b[1] >= g[0] - 1 && g[0] * 2 + 2 >= b[1])) {
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