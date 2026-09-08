#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	if (b == 1) cout << 0 << "\n";
	else if (b == a) cout << 1 << "\n";
	else cout << 1 + ceil (1.0 * (b - a) / (a - 1)) << "\n";


	return 0;
}