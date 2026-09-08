#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int inf = 1E9; 

void solve () {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector <vector <int>> a(m + 1);
	
	for (int i = 0; i < n; i ++ ) {
		int x, y;
		cin >> x >> y;
		
		a[x].push_back (y);
	}
	
	int cnt = 0;
	
	for (int i = 1; i <= m; i ++ ) {
		int minn = inf;
		for (int j = 0; j < a[i].size (); j ++ ) {
			minn = min (minn, a[i][j]);
		}
		cnt += minn;
	}
	
	cout << min (k, cnt) << "\n"; 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 