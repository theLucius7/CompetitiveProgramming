#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s = "atcoder";

	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i ++ ) {
		cout << s[i - 1];
	}

	return 0;
}