#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m;

LL re (LL x) {
	LL ans = 0;
	while (x) {
		ans =ans * 10 + x % 10;
		x /= 10;
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	LL res = 0;

	LL k = m;
	while (k <= n) {
		res ++ ;
		k *= 10;
	}

	LL re_k = re (m);
	while (re_k <= n) {
		res ++ ;
		re_k *= 10;
	}

	cout << res << "\n";

	return 0;
}