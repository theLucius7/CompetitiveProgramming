#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	if ((b >= a && b <= c) || (b <= a && b >= c)) cout << "Yes" << "\n";
	else cout << "No" << "\n";


	return 0;
}