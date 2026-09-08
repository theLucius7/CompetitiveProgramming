#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	s = ' ' + s;

	vector <int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}

	int sum = 0;
	int i = 1;

	while (s[i] == '1') {
		sum += a[i];
		i ++ ;
	}

	for (int j = i; j <= n; j ++ ) {
		int k = j + 1;
		int minn = a[j];
		int res = a[j];
		
		while (s[k] == '1') {
			minn = min (minn, a[k]);
			res += a[k];
			k ++ ;
		}

		if (k != j + 1) {
			res -= minn;
			sum += res;
		}

		j = k - 1;
	}

	cout << sum << "\n";
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