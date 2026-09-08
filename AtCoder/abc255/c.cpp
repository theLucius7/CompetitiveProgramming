#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LL x, a, d, n;
	cin >> x >> a >> d >> n;

	if (d == 0) {
		cout << abs (x - a) << "\n";
		return 0;
	}
	
	LL y = x - a;

	LL f = abs (y / d);



	if (f > n - 1) {
		cout << min (abs (y), abs (x - (n - 1) * d - a)) << "\n";
	} else {
		cout << min (abs ((f + 1) * d + a - x), abs (f * d + a - x)) << "\n";
	}


	return 0;
}