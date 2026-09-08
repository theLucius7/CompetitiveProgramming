#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	vector <int> s(N);
	for (int i = 0; i < n; i ++ ) {
		s[a[i]] ++ ;
	}
	for (int i = 1; i <= N; i ++ ) {
		s[i] += s[i - 1];
	}

	LL res = 0;
	for (int i = 0; i < n; i ++ ) {
		res += (LL)s[a[i] - 1] * (n - s[a[i]]);
	}

	cout << res << "\n";

	return 0;
}