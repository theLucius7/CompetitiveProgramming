#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	i64 ans = 0;
	i64 a, len;
	
	for(int i = 0; i < n; i ++ ) {
		cin >> a >> len;
		
		if (a % 2) {
			ans ^= a;
			
			len -- ;
			a ++ ;
		}
		
		if (len && len % 2) {
			ans ^= a + len - 1;
			
			len -- ;
		}
		
		if (len && (len / 2) % 2) {
			ans ^= 1;
		}
	} 
	
	if (ans) {
		cout << "tolik\n";
	} else {
		cout << "bolik\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 