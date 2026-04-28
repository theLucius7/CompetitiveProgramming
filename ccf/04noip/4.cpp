#include <bits/stdc++.h>

using namespace std;

typedef long long i64; 

constexpr int N = 30;

int n;
string s[3]; 
int q[N], path[N];
bool st[N];

bool check () {
	int t = 0;
	for (int i = n - 1; i >= 0; i -- ) {
		int a = path[s[0][i] - 'A'], b = path[s[1][i] - 'A'], c = path[s[2][i] - 'A'];
		if (a != -1 && b != -1 && c != -1) {
			if (t == -1) {
				if ((a + b) % n != c && (a + b + 1) % n != c) {
					return false;
				}
				if (!i && a + b >= n) {
					return false;
				}
			} else {
				if ((a + b + t) % n != c) {
					return false;
				}
				if (!i && a + b + t >= n) {
					return false;
				}
				t = (a + b + t) / n;
			}
		} else {
			t = -1;
		}
	}
	return true;
}

bool dfs (int u) {
	if (u == n) {
		return true;
	}	
	
	for (int i = 0; i < n; i ++ ) {
		if (!st[i]) {
			st[i] = true;
			path[q[u]] = i;
			if (check () && dfs (u + 1)) {
				return true;
			}		
			path[q[u]] = -1;
			st[i] = false;
		}
	}
	
	return false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	
	for (int i = 0; i < 3; i ++ ) {
		cin >> s[i];
	}
	
	int cnt = 0;
	for (int i = n - 1; i >= 0; i -- ) {
		for (int j = 0; j < 3; j ++ ) {
			int c = s[j][i] - 'A';
			if (!st[c]) {
				st[c] = true;
				q[cnt ++ ] = c;
			}
		}
	}
	
	memset (st, false, sizeof st);
	memset (path, -1, sizeof path);
	
	dfs (0);
	
	for (int i = 0; i < n; i ++ ) {
		cout << path[i] << " \n"[i == n - 1];
	}
	
	return 0;
}
