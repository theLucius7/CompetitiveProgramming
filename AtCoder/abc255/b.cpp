#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <int> b(m);
	vector <bool> st(n, false);
	for (int i = 0; i < m; i ++ ) {
		int x;
		cin >> x;
		x -- ;
		b[i] = x;
		st[x] = true;
	}
	
	vector <PII> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i].x >> a[i].y;
	}

	

	double res = 0;
	for (int i = 0; i < n; i ++ ) {
		if (st[i] == false) {
			double ans = 999999999;
			for (int j = 0; j < m; j ++ ) {
				double h = sqrt (pow (a[b[j]].x- a[i].x, 2) + pow (a[b[j]].y - a[i].y, 2));
				ans = min (ans, h);
			}
			res = max (res, ans);
		}
		
	}

	cout << fixed << setprecision (9) << res << "\n";

	return 0;
}