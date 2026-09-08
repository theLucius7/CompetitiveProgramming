#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

bool wina, winb;
string s[3];

void dfs (int a, int b, int x, int y, int d, char c) {
	if (d == 3) {
		if (c == 'X') {
			wina = true;
		} else {
			winb = true;
		}
		return;
	}
	
	if (x + a >= 0 && x + a < 3 && y + b >= 0 && y + b < 3 && s[x + a][y + b] == c) {
		dfs (a, b, x + a, y + b, d + 1, c);
	}
}

void solve () {
	int cnta = 0, cntb = 0;
	
	for (int i = 0; i < 3; i ++ ){
		cin >> s[i];
		for (int j = 0; j < 3; j ++ ) {
			if (s[i][j] == 'X') {
				cnta ++ ;
			} else if (s[i][j] == '0') {
				cntb ++ ;
			}
		}
	} 
		
	if (cntb > cnta || cnta > cntb + 1) {
		cout << "illegal\n";
		return;
	}
	
	for (int i = 0; i < 3; i ++ ) {
		for (int j = 0; j < 3; j ++ ) {
			if (s[i][j] != '.') {
				for (int a = -1; a <= 1; a ++ ) {
					for (int b = -1; b <= 1; b ++ ) {
						if (a != 0 || b != 0) {
							dfs (a, b, i, j, 1, s[i][j]); 
						} 
					}
				}
			} 
		}
	}
	
	if ((wina && winb) || (wina && cnta == cntb) || (winb && cnta == cntb + 1)) {
		cout << "illegal\n";
	} else if (wina) {
		cout << "the first player won\n";
	} else if (winb) {
		cout << "the second player won\n";
	} else if (cnta + cntb == 9) {
		cout << "draw\n";
	} else if (cnta == cntb + 1) {
		cout << "second\n";
	} else {
		cout << "first\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}