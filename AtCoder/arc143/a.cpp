#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector <LL> a(3);
	for (int i = 0; i < 3; i ++ ) {
		cin >> a[i];
	}
	
	sort (a.begin (), a.end ());
	
	if (a[2] > a[0] + a[1]) {
		cout << "-1\n";
	} else {
		cout << a[2] << "\n";
	}
		
	return 0;
}