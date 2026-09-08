#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LL n, m;
	cin >> n >> m;

	LL a = n % m;
	LL b = m - a;

	cout << min (a, b) << "\n";

	return 0;
}