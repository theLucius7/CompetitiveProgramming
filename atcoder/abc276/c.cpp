#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	prev_permutation (a.begin (), a.end ());

	for (int i = 0; i < n; i ++ ) {
		cout << a[i] << " \n"[i == n - 1];
	}	
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}