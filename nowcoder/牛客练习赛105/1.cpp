#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	if (n % 16 == 0 && n >= 16) {
		cout << "5\n";
	} else {
		cout << "-1\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}