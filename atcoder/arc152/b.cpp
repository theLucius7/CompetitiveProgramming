#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, s;
	cin >> n >> s;

	vector <int> a(n);
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		if (a[i] == 2) {
			cnt2 ++ ;
		} else {
			cnt1 ++ ;
		}
	}

	if ((cnt2 == 1 && cnt1 != 0) || cnt2 == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}