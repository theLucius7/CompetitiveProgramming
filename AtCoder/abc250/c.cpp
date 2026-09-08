#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <int> val(n + 1), pos(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		val[i] = i;
		pos[i] = i;
	}

	while (m -- ) {
		int x;
		cin >> x;

		int p0 = pos[x];
		int p1;
		if (p0 == n) p1 = p0 - 1;
		else p1 = p0 + 1;

		int v0 = val[p0];
		int v1 = val[p1];
		swap (val[p0], val[p1]);
		swap (pos[v0], pos[v1]);
	}

	for (int i = 1; i <= n; i ++ ) {
		cout << val[i] << " ";
	}

	cout << "\n";

	return 0;
}