#include <bits/stdc++.h>

using namespace std;

const int N = 410, M = 2e5 + 10;

int n;
int a[N], b[N];

int cnt;
int cnta, cntb;
char ans_a[M], ans_b[M];
int res_a[M], res_b[M];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort (b, b + n);

	int it = n - 1;
	while (it != 0) {
		int x;
		for (int i = 0; i <= it; i ++ ) {
			if (a[i] == b[it]) {
				x = i;
			}
		}

		while (x + 2 <= it) {
			swap (a[x], a[x + 2]);
			cnt ++ ;
			cntb ++ ;
			ans_b[cntb] = 'B';
			res_b[cntb] = x + 1;
			x += 2;
		}

		if (x != it) {
			swap (a[x], a[x + 1]);
			
			cnt ++ ;
			cnta ++ ;
			ans_a[cnta] = 'A';
			res_a[cnta] = x + 1;

			x ++ ;
		}

		it -- ;
	}

	cout << cnt << "\n";

	for (int i = 1; i <= cntb; i ++ ) {
		cout << ans_b[i] << " " << res_b[i] << "\n";
	}
	for (int i = 1; i <= cnta; i ++ ) {
		cout << ans_a[i] << " " << res_a[i] << "\n";
	}


	return 0;
}