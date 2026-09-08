// LUOGU_RID: 92277241
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		a[i] = s[i] - '0';
	}

	for (int i = n - 1; i; i -- ) {
		a[i] ^= a[i - 1];
	}

	int c = count (a.begin (), a.end (), 1);
	cout << max (0, c - 1) << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		solve ();
	}

	return 0;
}