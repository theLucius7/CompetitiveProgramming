#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <int, int> pii;

void solve () {
	int x = 0, y = 0, cnt = 0;
	map <pii, int> mp;
	
	for (int i = 0; i < 4; i ++ ) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if (x1 != x2 && y1 != y2) {
			cout << "NO\n";
			return;
		}
		
		mp[{x1, y1}] ++ , mp[{x2, y2}] ++ ;
		if (mp[{x1, y1}] == 2) {
			cnt ++ ;
		}
		if (mp[{x2, y2}] == 2) {
			cnt ++ ;
		}
		
		if (x1 == x2) {
			x ++ ;
		}
		if (y1 == y2) {
			y ++ ;
		}
	}
	
	if (x != 2 || y != 2 || cnt != 4) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 