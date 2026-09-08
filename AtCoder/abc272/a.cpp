#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i]; 
	} 
	
	cout << accumulate (a.begin (), a.end (), 0) << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 