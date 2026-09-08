#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		int minx = 0, miny = 0;
		int maxx = 0, maxy = 0;

		for (int i = 0; i < n; i ++ ) {
			int x, y;
			cin >> x >> y;
			minx = min (minx, x), maxx = max (maxx, x);
			miny = min (miny, y), maxy = max (maxy, y);
		}

		cout << (maxx - minx) * 2 + (maxy - miny) * 2 << "\n";
	}

	return 0;
}