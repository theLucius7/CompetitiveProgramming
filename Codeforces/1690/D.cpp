#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n, m;
		cin >> n >> m;

		string s;
		cin >> s;

		vector <int> sum (n);
		for (int i = 0; i < n; i ++ ) {
			sum[i] = (i == 0 ? 0 : sum[i - 1]) + (s[i] == 'W');
		}

		int res = INF;
		for (int i = 0; i + m - 1 < s.size (); i ++ ) {
			res = min (res, sum[i + m - 1] - (i == 0 ? 0 : sum[i - 1]));
		}

		cout << res << "\n";
	}


	return 0;
}