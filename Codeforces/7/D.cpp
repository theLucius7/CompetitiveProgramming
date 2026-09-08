#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1E7 + 10;

int n;
char a[N], b[N];
int p[N];
int f[N];

void init () {
	cin >> a;
	n = strlen (a);
	
	int k = 0;
	b[k ++ ] = '$', b[k ++ ] = '#';
	
	for (int i = 0; i < n; i ++ ) {
		b[k ++ ] = a[i];
		b[k ++ ] = '#';
	}
	
	b[k ++ ] = '^';
	
	n = k;
}

void manacher () {
	int mr = 0, mid;
	for (int i = 0; i < n; i ++ ) {
		if (i < mr) {
			p[i] = min (p[2 * mid - i], mr - i);
		} else {
			p[i] = 1; 
		} 
		
		while (b[i - p[i]] == b[i + p[i]]) {
			p[i] ++ ;
		} 
		
		if (i + p[i] > mr) {
			mr = i + p[i];
			mid = i;
		}
	}
}

void solve () {
	init ();
	
	manacher ();
	
	for (int i = 2; i < n; i ++ ) {
		if (p[i] == i) {
			f[i] = f[(i + 1) / 2] + 1;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i ++ ) {
		ans += f[i];
	}
	
	cout << ans << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 