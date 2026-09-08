#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 3E5 + 10;

int a[N];

void solve () {
	int n;
	cin >> n;
	
	map <int, int> b;

	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i]; 
		b[a[i]] ++ ;
	} 
	
	sort (a + 1, a + n + 1);
	
	int i = 1;
	int ans = 0;
	
	while (i < n) {
		if (b[ans + 1]) {
			b[ans + 1] -- ;
			ans ++ ;
			i ++ ;
		} else {
			for (int j = 0; j <= 1; j ++ ) {
				if (i <= n - j) {
					b[a[n - j]] -- ;
					if (i == n - j) {
						i ++ ;
					}
				} else {
					cout << ans << "\n";
					return;
				}
			}
			n -= 2;
			ans ++ ;
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