#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x, t, d;
	cin >> n >> m >> x >> t >> d;

	cout << t - max (0, x - m) * d << "\n";

	return 0;
}