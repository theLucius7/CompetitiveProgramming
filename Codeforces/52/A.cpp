#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	vector <int> a(n);
	vector <int> b(4);
	
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		b[a[i]] ++ ;
	} 

	cout << n - max ({b[1], b[2], b[3]}) << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}