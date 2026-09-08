#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int n;
int cnt;

void dfs (int u) {
	if (u > n) {
		return;
	}
	
	cnt ++ ;
	
	dfs (u * 10);
	dfs (u * 10 + 1);
}

void solve () {
	cin >> n;
	
	dfs (1);
	
	cout << cnt << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}