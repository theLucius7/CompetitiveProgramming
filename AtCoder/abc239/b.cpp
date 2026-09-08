#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	LL x;
	cin >> x;

	if (x >= 0) {
		cout << x / 10 << "\n";
	} else {
		cout << (x - 9) / 10 << "\n";
	}

	return 0;
}