#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> PII;

const int N = 1000;

string s[3][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		unordered_map <string, int> cnt;

		for (int i = 0; i < 3; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				cin >> s[i][j];
				cnt[s[i][j]] ++ ;
			}
		}

		int res[3];
		memset (res, 0, sizeof res);

		for (int i = 0; i < 3; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				if (cnt[s[i][j]] == 1) {
					res[i] += 3;
				} else if (cnt[s[i][j]] == 2) {
					res[i] += 1;
				}
			}
		}

		for (int i = 0; i < 3; i ++ ) {
			cout << res[i] << " \n"[i == 2];
		}
	}

	return 0;
}