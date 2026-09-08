#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	unordered_map <string, int> mp;


	for (int i = 0; i < n; i ++ ) {
		string s;
		cin >> s;

		if (!mp[s]) {
			cout << "OK\n";
		} else {
			cout << s << mp[s] << "\n";
		}

		mp[s] ++ ;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}