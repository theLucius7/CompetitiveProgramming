#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	string s;
	cin >> s;
	
	sort (s.begin (), s.end ());
	
	int idx = 0;
	while (s[idx] == '0' && idx + 1 < s.size ()) {
		idx ++ ;
	}
	
	swap (s[idx], s[0]);
			
	string p;
	cin >> p;
	
	if (s == p) {
		cout << "OK\n";
	} else {
		cout << "WRONG_ANSWER\n";
	}
	
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}