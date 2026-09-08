#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string s;
	cin >> s;
	
	stack <int> stk;
	
	vector <bool> st(s.size () + 1);
	
	for (int i = 0; i < (int)s.size (); i ++ ) {
		if (s[i] == '(') {
			stk.push (i);
		} else {
			if (stk.size ()) {
				st[i] = true;
				st[stk.top ()] = true;
				stk.pop ();
			}
		}
	}
	
	int now = 0;
	int maxn = 0, cnt = 1;
	for (int i = 0; i < (int)s.size () + 1; i ++ ) {
		if (st[i]) {
			now ++ ;
		} else {
			if (now > maxn) {
				maxn = now;
				cnt = 1;
			} else if (now == maxn && now) {
				cnt ++ ;
			}
			now = 0;
		}
	}
	
	cout << maxn << " " << cnt << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}//