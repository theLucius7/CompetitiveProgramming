#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 146097;

LL n;
int y[N], m[N], d[N];

int calc (int year, int month) {
	if (month == 2) {
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28;
	}
	return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	y[0] = 0, m[0] = 1, d[0] = 1;
	for (int i = 1; i < N; i ++ ) {
		d[i] = d[i - 1] + 1, m[i] = m[i - 1], y[i] = y[i - 1];
		if (d[i] > calc (y[i], m[i])) {
			m[i] ++ , d[i] = 1;
			if (m[i] > 12) {
				y[i] ++ ;
				m[i] = 1;
			}
		}
	}

	while (T -- ) {
		cin >> n;

		int t;
		if (n > ((1581 + 4713) * 365 + (1581 + 4713) / 4 + 1 + 273 + 3)) {
			n = n + 11 - ((1199 + 4713) * 365 + (1199 + 4713) / 4 + 1) - 3;
			t = n / N * 400 + 1200;
			n %= N;
		} else {
			t = n / (365 * 4 + 1) * 4 - 4712;
			n %= (365 * 4 + 1);
		}

		if (t + y[n] > 0) {
			cout << d[n] << " " << m[n] << " " << t + y[n] << "\n";
		} else {
			cout << d[n] << " " << m[n] << " " << 1 - (t + y[n]) << " BC\n";
		}
	}

	return 0;
}