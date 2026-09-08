#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int x;
	char c;
	vector <bool> have (1010);	

	while (cin >> x) {
		cin >> c;
		have[x] = true;
	} 
	
	bool flag = false;
	
	for (int i = 1; i <= 1000; i ++ ) {
		if (have[i]) {
			int j = i, cnt = 1;
			while (have[j]) {
				j ++ ;
			}
			
			if (!flag) {
				flag = true;
			} else {
				cout << ",";
			}
			
			if (j - i > 1) {
				cout << i << "-" << j - 1;
			} else {
				cout << i;
			}
			
			i = j;
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
} 