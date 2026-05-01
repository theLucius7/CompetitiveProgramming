#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	if (s[0] != '>' || s.substr(n - 3, 3) != ">>>" || s.find('-') == std::string::npos) {
		cout << "No\n";
		return;
	}

	std::vector<std::pair<int, int>> ans;
	
	int r = n - 3;
	while (s[r] != '-') {
		ans.push_back({1, r + 3});
		r -- ;
	}
	for (int i = 1; i < r; i ++ ) {
		if (s[i] == '>') {
			ans.push_back({i + 1, r + 4 - i});
		}
	}
	cout << "Yes " << ans.size() << endl;
	for (auto [x, y] : ans) {
		cout << x << " " << y << endl;
	}
}

int main() {

	int t;
	cin >> t;
	while (t -- ) {
		solve();
	}
	

	return 0;
}