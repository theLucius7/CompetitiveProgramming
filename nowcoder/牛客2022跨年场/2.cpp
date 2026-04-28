#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	unordered_map <int, int> mp;

	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		mp[x] ++ ;
	}

	int cnt = 0;

	for (auto x : mp) {
		if (x.second % 2) {
			cnt ++ ;
		}
	}

	if (cnt % 2){
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

	return 0;
}