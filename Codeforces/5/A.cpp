#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n = 0, res = 0;

	std::string s;
	while (std::getline (std::cin, s)) {
		if (s[0] == '+') {
			n ++ ;
		} else if (s[0] == '-') {
			n -- ;
		} else {
			int idx = 0;
			while (s[idx] != ':') {
				idx ++ ;
			}
			res += (s.size () - 1 - idx) * n;
		}
	}
	
	std::cout << res << "\n";
} 

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 