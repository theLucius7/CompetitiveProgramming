#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 2E5 + 10;

unordered_map <i64, int> a;

void solve () {
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ ) {
		int x;
		cin >> x;
		
		for (int j = 1; j <= x; j ++ ) {
			int y;
			cin >> y;
			a[i * N + j] = y;
		}
	}
	
	for (int i = 0; i < m; i ++ ) {
		int x, y;
		cin >> x >> y;
		cout << a[x * N + y] << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 