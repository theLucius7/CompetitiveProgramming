#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	std::vector <int> a(4);
	for (int i = 0; i < 4; i ++ ) {
		std::cin >> a[i];
	} 
	
	sort (a.begin (), a.end ());
	
	if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) {
		std::cout << "TRIANGLE\n";
	} else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) {
		std::cout << "SEGMENT\n";
	} else {
		std::cout << "IMPOSSIBLE\n";
	}
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 