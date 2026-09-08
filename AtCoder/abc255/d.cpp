#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	sort (a.begin (), a.end ());

	vector <LL> s(n);
	for (int i = 0; i < n; i ++ ) {
		s[i] = (i == 0 ? 0 : s[i - 1]) + a[i];
	}

	while (m -- ) {
		LL x;
		cin >> x;

		int low;
		low = lower_bound (a.begin (), a.end (), x) - a.begin ();
		LL res = x * low - (low == 0 ? 0 : s[low - 1]) + s[n - 1] - (low == 0 ? 0 : s[low - 1]) - x * (n - low);
		cout << res << "\n";
	}
	
	return 0;
}