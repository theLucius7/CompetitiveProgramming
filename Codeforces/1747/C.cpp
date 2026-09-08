#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int inf = 1E9;

void solve () {
	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}

	if (a[0] == *min_element (a.begin (), a.end ())) {
		cout << "Bob\n";
	} else {
		cout << "Alice\n";
	}
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