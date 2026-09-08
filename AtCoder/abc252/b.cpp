#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];
bool st[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	int maxv = 0;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		maxv = max (maxv, a[i]);
	} 
	
	for (int i = 1; i <= m; i ++ ) {
		int x;
		cin >> x;
		st[x] = true;
	}
	
	for (int i = 1; i <= n; i ++ ) {
		if (a[i] == maxv && st[i] == true) {
			cout << "Yes";
			return 0;
		}
	} 
	
	cout << "No";
	
	
	return 0;
}