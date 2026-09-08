#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	
	while (T -- ) {
		string s;
		cin >> s;
		
		int a = stoi (s);
		
		cout << a - (int)pow (10, s.size () - 1) << "\n"; 
	} 
	
	return 0; 
}