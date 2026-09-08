#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 10, M = 1e7 + 10;

int n;
int a[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = M + 1; i <= M + n; i ++ ) {
		cin >> a[i];
	}

	sort (a + M + 1, a + M + n + 1);

	int l = M + 1, r = M + n;
	int cnt = 0;
	
	while (r - l + 1) {
		if (a[r] % a[l] != 0) {
			a[l - 1] = a[r] % a[l];
			l -- ;
		}

		r -- ;
		cnt ++ ;
	}

	cout << cnt - 1 << "\n";

	return 0;
}