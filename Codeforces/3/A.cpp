#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	std::string s, e;
	std::cin >> s >> e;
	
	int x = e[0] - s[0], y = e[1] - s[1];
	
	char px, py;
	if (x < 0) {
		px = 'L';
	} else {
		px = 'R';
	}
	
	if (y < 0) {
		py = 'D';
	} else {
		py = 'U';
	}
	
	x = abs (x), y = abs (y);
	
	std::cout << std::max (x, y) << "\n";
	
	while (x || y) {
		if (x) {
			x -- ;
			std::cout << px;
		}
		
		if (y) {
			y -- ;
			std::cout << py;
		}
		std::cout << "\n";
	}
} 

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 