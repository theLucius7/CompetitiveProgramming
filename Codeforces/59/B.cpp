#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int inf = 1E9 + 10;

void solve () {
	int n;
	cin >> n;

	int minn = inf, cnt = 0;
	int ans = 0;
	vector <int> a(n);

	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];

		ans += a[i];

		if (a[i] % 2) {
			minn = min (minn, a[i]);
			cnt ++ ;
		}
	}

	if (cnt == 0) {
		cout << "0\n";
	} else {
		if (cnt % 2 == 0) {
			ans -= minn;
		}

		cout << ans << "\n";
	}

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}