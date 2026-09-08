#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

int n, m;
char str[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	cin >> str + 1;

	int cnt = 0;
	for (int i = 0; i < m; i ++ ) {
		int op, x;
		cin >> op >> x;

		if (op == 1) {
			cnt += x;
			cnt %= n;
		} else {
			if (x > cnt) {
				cout << str[x - cnt] << '\n';
			} else {
				cout << str[n - cnt + x] << '\n';
			}
		}
	}



	return 0;
}