#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int inf = 1E9;

void solve () {
	int n;
	cin >> n;
	
	int mina = inf;
	vector <int> a(n);
	
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		mina = min (mina, a[i]);
	}
	
	int ans = inf;
	
	for (int i = 0; i < n; i ++ ) {
		if (a[i] != mina) {
			ans = min (ans, a[i]);
		}
	}

	if (ans == inf) {
		cout << "NO\n";
	} else {
		cout << ans << "\n";
	}

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}