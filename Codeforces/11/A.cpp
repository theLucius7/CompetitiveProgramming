#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, d;
	cin >> n >> d;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	
	int cnt = 0;
	
	for (int i = 1; i < n; i ++ ) {
		if (a[i - 1] >= a[i]) {
			cnt += ((a[i - 1] - a[i]) / d + 1);
			a[i] += ((a[i - 1] - a[i]) / d + 1) * d;
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