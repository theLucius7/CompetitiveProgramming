#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LL n, m;
	cin >> n >> m;

	if (n == 1 || m == 1) cout << 1 << "\n";
	else cout << (n * m + 1) / 2 << "\n";


	return 0;
}