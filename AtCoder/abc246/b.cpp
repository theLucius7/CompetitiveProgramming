#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	
	double c = sqrt (a * a + b * b);

	cout << fixed << setprecision (10) << a / c << " " << b / c << "\n";

	return 0;
}