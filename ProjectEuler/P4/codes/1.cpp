#include <bits/stdc++.h>

using i64 = long long;

bool check (int x) {
	std::string s, t;
	s = t = std::to_string (x);
	std::reverse (t.begin (), t.end ());

	if (s == t) {
		return true;
	}
	return false;
}

void solve () {
	int max = 0;
	for (int i = 100; i < 1000; i ++ ) {
		for (int j = 100; j < 1000; j ++ ) {
			if (check (i * j)) {
				max = std::max (max, i * j);
			}
		}
	}
	std::cout << max << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}