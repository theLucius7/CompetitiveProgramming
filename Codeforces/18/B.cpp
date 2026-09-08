#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, d, m, l;
	cin >> n >> d >> m >> l;
	
	i64 ans = 0;
	
	for (int i = 1; i <= n; i ++ ) {
		if (ans < (i64)(i - 1) * m) {
			break;
		}
		
		if (ans <= (i64)(i - 1) * m + l) {
			ans = (((i64)(i - 1) * m  + l) / d * d) + d;
		}
	}
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}