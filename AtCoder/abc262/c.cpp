#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n;
int a[N];
LL cnt;
LL res;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];

		if (a[i] == i) {
			cnt ++ ;
		} else if (a[i] < i) {
			if (a[a[i]] == i) {
				res ++ ;
			}
		}
	}

	res += cnt * (cnt - 1) / 2;

	cout << res << "\n";

	return 0;
}