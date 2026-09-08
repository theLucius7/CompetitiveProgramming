#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 20;

void solve () {
	i64 x;
	int k;
	cin >> x >> k;
	
	int len = 0;
	i64 y = x;
	while (y) {
		y /= 10;
		len ++ ;
	}
	
	for (int i = 1; i <= min (k, len + 1); i ++ ) {
		i64 z = x;
		z /= pow (10, i - 1);
		bool flag = (z % 10 >= 5);
		z /= 10;
		z += flag;
		x = z * pow (10, i);
	}
	
	cout << x << "\n";
} 

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}