#include <bits/stdc++.h>

using namespace std;

const int N = 14;

int a[5];
int st[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i ++ ) {
		cin >> a[i];
		st[a[i]] ++ ;
	}

	bool ok1 = false, ok2 = false;
	for (int i = 0; i < 14; i ++ ) {
		if (st[i] == 2) {
			ok1 = true;
		} else if (st[i] == 3) {
			ok2 = true;
		}
	}

	if (ok1 && ok2) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}