#include <bits/stdc++.h>

using namespace std;

void solve () {
	int n;
	cin >> n;
	
	vector <int> have(3010);
	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		have[x] ++ ;
	}
	
	for (int i = 1; i <= 3001; i ++ ) {
		if (!have[i]) {
			cout << i << "\n";
			break;
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	
	return 0;
}