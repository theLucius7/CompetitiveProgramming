#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	
	int cnt = 0;
	LL res = 0;
	for (int i = s.size () - 1; i >= 0; i -- ) {
		if (s[i] == 'W') {
			cnt ++ ;
		} else {
			res += cnt;
		}
	}

	cout << res << "\n";


	return 0;
}