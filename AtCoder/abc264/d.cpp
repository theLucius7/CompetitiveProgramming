#include <bits/stdc++.h>

using namespace std;

string p = "atcoder";
string s;
int cnt;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;

	for (int i = 0; i < p.size (); i ++ ) {
		for (int j = 0; j < s.size (); j ++ ) {
			if (s[j] == p[i]) {
				int x = j;
				while (x != i) {
					swap (s[x], s[x - 1]);
					x -- ;
					cnt ++ ;
				}
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}