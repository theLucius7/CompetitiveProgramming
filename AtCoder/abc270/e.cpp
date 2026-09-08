#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1e5 + 10;

i64 n, m;
i64 a[N];

bool check (i64 x) {
	i64 sum = 0;
	for (int i = 0; i < n; i ++ ) {
		sum += min (a[i], x);
	}
	return sum <= m;
}

void solve () {
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	
	i64 l = 0, r = 1e12 + 10;
	while (l < r) {
		i64 mid = l + r + 1 >> 1; 
		if (check (mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	
	for (int i = 0; i < n; i ++ ) {
		i64 d = min (l, a[i]);
		a[i] -= d;
		m -= d;
	}
	
	int idx = 0;
	while (m) {
		if (a[idx]) {
			m -- ;
			a[idx] -- ;
		}
		
		idx ++ ;
	}
	
	for (int i = 0; i < n; i ++ ) {
		cout << a[i] << " \n"[i == n - 1];	
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 