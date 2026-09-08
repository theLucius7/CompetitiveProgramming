#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	cout << n * 2 << "\n";
	
	int x = n % 4;
	int y = n / 4;
	
	if (x) {
		cout << x;
	}
	for (int i = 0; i < y; i ++ ) {
		cout << 4;
	}
	
	return 0;
}