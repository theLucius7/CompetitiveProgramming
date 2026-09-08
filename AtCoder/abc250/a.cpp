#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int x, y;
	cin >> x >> y;

	int res = 0;
	if (x > 1) res ++ ;
	if (x < n) res ++ ;
	if (y > 1) res ++ ;
	if (y < m) res ++ ;

	cout << res << "\n";


	return 0;
}