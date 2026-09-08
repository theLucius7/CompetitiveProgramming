#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	double n, vb, vs;
	cin >> n >> vb >> vs;
	
	vector <int> xi(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> xi[i];
	}
	
	double xn, yn;
	cin >> xn >> yn;
	
	vector <double> d(n);
	for (int i = 1; i < n; i ++ ) {
		d[i] = sqrt (1.0 * (xn - xi[i]) * (xn - xi[i]) + 1.0 * yn * yn);
	}
	
	double t = 1E9, g = 1E9;
	int ans;
	
	for (int i = 1; i < n; i ++ ) {
		double ti = 1.0 * d[i] / vs + 1.0 * xi[i] / vb;
		if (ti < t || (ti == t && d[i] < g)) {
			t = ti;
			g = d[i];
			ans = i;
		}
	}
	cout << ans + 1 << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}