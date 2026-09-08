#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	int res = n % (a + b + c);
	if (res < a) cout << "F" << "\n";
	else if (res < a + b) cout << "M" << "\n";
	else cout << "T" << "\n";
	
	return 0;
}