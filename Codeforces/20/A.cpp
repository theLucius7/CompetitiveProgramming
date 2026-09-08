#include <bits/stdc++.h>

using namespace std;

void solve () {
	string s;
	cin >> s;

	int idx = s.size () - 1;

	while (s[idx] == '/') {
		idx -- ;
	}

	if (idx < 0) {
		cout << "/\n";
		return;
	}

	bool flag = false;
	for (int i = 0; i <= idx; i ++ ) {
		if (flag) {
			if (s[i] != '/') {
				flag = false;
				cout << s[i];
			}
		} else {
			if (s[i] == '/') {
				flag = true;
			}
			cout << s[i];
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