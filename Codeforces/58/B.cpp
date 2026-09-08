#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	int k = 2;
	while (n != 1) {
		if (n % k) {
			k ++ ;
		} else {
			cout << n << " ";
			n /= k;
		}
	}
	
	cout << "1\n"; 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 