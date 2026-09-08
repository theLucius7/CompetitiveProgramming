#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	int ans = 1;
	for (int i = 1; i <= n; i ++ ) {
		ans *= i;
	}
	
	cout << ans << "\n"; 
} 

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}