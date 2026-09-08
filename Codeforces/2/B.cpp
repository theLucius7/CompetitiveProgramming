#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1010;

int f[N][N][2];

void solve () {
	int n;
	cin >> n;
	
	memset (f, sizeof f, 0);
	
	int pos = -1;
	
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j ++ ) {
			int x;
			cin >> x;
			
			if (!x) {
				pos = i;
			} else {
				while (x % 2 == 0) {
					f[i][j][0] ++ ;
					x /= 2;
				}
				while (x % 5 == 0) {
					f[i][j][1] ++ ;
					x /= 5;
				}
			}
		}
	}

	for (int i = 2; i <= n; i ++ ) {
		f[i][1][0] += f[i - 1][1][0];
		f[i][1][1] += f[i - 1][1][1];
		
		f[1][i][0] += f[1][i - 1][0];
		f[1][i][1] += f[1][i - 1][1];
	} 
	
	for (int i = 2; i <= n; i ++ ) {
		for (int j = 2; j <= n; j ++ ) {
			f[i][j][0] += min (f[i - 1][j][0], f[i][j - 1][0]);
			f[i][j][1] += min (f[i - 1][j][1], f[i][j - 1][1]);
		}
	} 
	
	int flag = f[n][n][0] < f[n][n][1] ? 0 : 1; 
	
	if (pos != -1 && f[n][n][flag] >= 1) {
		cout << "1\n";
		for (int i = 1; i < pos; i ++ ) {
			cout << "D";
		}
		for (int j = 1; j < n; j ++ ) {
			cout << "R";
		}
		for (int i = pos; i < n; i ++ ) {
			cout << "D";
		}
		return;
	}
	
	string ans;
	
	int i = n, j = n;
	while (true) {
		if (f[i - 1][j][flag] < f[i][j - 1][flag]) {
			i -- ;
			ans += "D";
		} else {
			j -- ;
			ans += "R";
		}
		
		if (i == 1) {
			for (int k = 1; k < j; k ++ ) {
				ans += "R";
			}
			break;
		}
		if (j == 1) {
			for (int k = 1; k < i; k ++ ) {
				ans += "D"; 
			}
			break;
		}
	}
	
	cout << f[n][n][flag] << "\n";
	
	for (int i = ans.size () - 1; i >= 0; i -- ) {
		cout << ans[i];
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}