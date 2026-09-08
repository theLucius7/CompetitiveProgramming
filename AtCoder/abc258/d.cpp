#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n, m;
int a[N], b[N];
LL s[N];
LL res = 0x7f7f7f7f7f7f7f7f;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i] >> b[i];
		s[i] = s[i - 1] + a[i] + b[i];
	}

	for (int i = 1; i <= n; i ++ ) {
		if (i > m) {
			break;
		}
		res = min (res, s[i] + (LL)(m - i) * b[i]);
	}
	cout << res << "\n";

	return 0;
}