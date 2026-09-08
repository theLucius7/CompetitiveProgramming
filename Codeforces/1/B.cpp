#include <bits/stdc++.h>

using i64 = long long;

const std::string p = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solve () {
	std::string s;
	std::cin >> s;

	int n = s.length ();

	bool flag = false;
	for (int i = 1; i < n; i ++ ) {
		if (isdigit (s[i - 1]) && isupper (s[i])) {
			flag = true;
			break;
		}
	}
	
	if (flag) {
		int num1 = 0, num2 = 0;
		
		int idx = 1;
		while (isdigit (s[idx])) {
			num1 = num1 * 10 + s[idx ++ ] - '0';
		}
		
		idx ++ ;
		while (isdigit (s[idx])) {
			num2 = num2 * 10 + s[idx ++ ] - '0';
		}
				
		int j = 0;
		std::vector <int> t(110);
		while (num2) {
			if (num2 % 26) {
				t[j ++ ] = num2 % 26 - 1;
			} else {
				t[j ++ ]= 25;
			}
			num2 = num2 / 26 - !(num2 % 26);
		}
		
		for (int i = j - 1; i >= 0; i -- ){
			std::cout << p[t[i]];
		}
		std::cout << num1 << "\n";
	} else {
		int num1 = 0, num2 = 0;
		
		int idx = 0;
		while (isupper (s[idx])) {
			num1 = num1 * 26 + s[idx ++ ] - 'A' + 1;
		}
		
		while (isdigit (s[idx])) {
			num2 = num2 * 10 + s[idx ++ ] - '0';
		}
		
		std::cout << "R" << num2 << "C" << num1 << "\n";
	}
	
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	
	while (T -- ) {
		solve ();
	} 
	
	return 0;
} 