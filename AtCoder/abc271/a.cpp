#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	string s;
	while (n) {
		int x = n % 16;
		if (x < 10) {
			s += x + '0';
		} else {
			s += (x - 10) + 'A';
		}
		n /= 16;
	} 
	
	while (s.size () < 2) {
		s += '0';
	}
	
	reverse (s.begin (), s.end ());
	
	cout << s << "\n"; 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 