#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <int, int> pii;

void solve () {
	int n;
	cin >> n;
	
	int p1, p2, p3, t1, t2;
	cin >> p1 >> p2 >> p3 >> t1 >> t2;
	
	int ans = 0;
	vector <pii> a(n);
	
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i].x >> a[i].y;
		ans += (a[i].y - a[i].x) * p1;
	}
	
	for (int i = 1; i < n; i ++ ) {
		int d = a[i].x - a[i - 1].y;
		if (d <= t1) {
			ans += d * p1;
		} else if (d <= t1 + t2) {
			ans += t1 * p1 + (d - t1) * p2;
		} else {
			ans += t1 * p1 + t2 * p2 + (d - t1 - t2) * p3;
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