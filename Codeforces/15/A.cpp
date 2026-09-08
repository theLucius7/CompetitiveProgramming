#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <double, double> pdd; 

constexpr int N = 1010;

void solve () {
	int n, t;
	cin >> n >> t;
	
	pdd p[N];
	
	for (int i = 0; i < n; i ++ ) {
		int x, d;
		cin >> x >> d;
		p[i] = {x - d * 1.0 / 2, x + d * 1.0 / 2}; 
	}
	
	sort (p, p + n);
	
	int cnt = 2;
	for (int i = 1; i < n; i ++ ) {
		if (p[i].x - p[i - 1].y > t) {
			cnt += 2;
		} else if (p[i].x - p[i - 1].y == t) {
			cnt ++ ;
		}
	}
	
	cout << cnt << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve (); 
	
	return 0;
}