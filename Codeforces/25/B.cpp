#include <bits/stdc++.h>

using namespace std;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;
	
	bool flag = false;
	
	if (n % 2 == 0) {
		flag = true;
	}
	
	for (int i = 0; i < n; i ++ ) {
		cout << s[i];
		if (flag) {
			if (i % 2 == 1 && i != n - 1) {
				cout << "-";
			}
		} else {
			if (i % 2 == 1 && i != n - 2) {
				cout << "-";
			}
		}
	}
	
	cout << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	
	return 0;
}