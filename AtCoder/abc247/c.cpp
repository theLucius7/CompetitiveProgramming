#include <bits/stdc++.h>

using namespace std;

void solve (int n) {
	if (n == 1) {
		cout << 1 << " ";
		return;
	}
	
	solve (n - 1);
	
	cout << n << " ";
	
	solve (n - 1);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	solve (n);
	
	return 0;
}