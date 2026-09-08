#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 30;

int c[N][N];

void init () {
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j <= i; j ++ ) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
        }
    }
}

void solve () {
	set <int> s;

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		s.insert (x);
	}

	int m = 10 - s.size ();

	cout << 6 * c[m][2] << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init ();

	int T;
	cin >> T;

	while (T -- ) {
		solve ();
	}

	return 0;
}