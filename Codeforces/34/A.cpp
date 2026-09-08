#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int inf = 1E9;

void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}	
	
	int ans = inf;
	int x, y;
	
	for (int i = 0; i < n; i ++ ) {
		if (abs (a[i] - a[(i + 1) % n]) < ans) {
			x = i + 1, y = (i + 1) % n + 1;
			ans = abs (a[i] - a[(i + 1) % n]); 
		}
	}
	
	cout << x << " " << y << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 