#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <int, int> pii;

void solve () {
	int n, m;
	cin >> n >> m;
	
	vector <pii> w(m);
	for (int i = 0; i < m; i ++ ) {
		cin >> w[i].y >> w[i].x;
	}
	
	sort (w.begin (), w.end (), greater <pii> ());
	
	int res = 0;
	int idx = 0;
	
	while (n != 0 && idx < m) {
		int d = min (w[idx].y, n);
		res += d * w[idx].x;
		n -= d;
		idx ++ ;
	}
	
	cout << res << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}