#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int n;
int fa[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 2; i <= n; i ++ ) {
		cin >> fa[i];
	}

	int res = 1;
	int x = n;
	while (fa[x] != 1) {
		x = fa[x];
		res ++ ;
	}

	cout << res << "\n";

	return 0;
}