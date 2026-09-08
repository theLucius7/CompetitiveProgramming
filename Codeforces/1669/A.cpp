#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t -- ) {
		int n;
		cin >> n;
		
		int res = 0;
		
		if (n <= 1399) res = 4;
		else if (n <= 1599) res = 3;
		else if (n <= 1899) res = 2;
		else res = 1;
		
		cout << "Division " << res << "\n";//
	}	
	
	return 0;
}