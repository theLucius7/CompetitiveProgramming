#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	
	std::string s, t;
	std::cin >> s >> t;

	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	std::cout << (s == t ? "YES" : "NO") << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}