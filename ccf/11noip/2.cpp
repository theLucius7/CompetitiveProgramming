#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10, M = 55;

int n, m, K;
int color[N];
LL s[M];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> K;

	LL res = 0;
	int t = -1;
	for (int i = 0; i < n; i ++ ) {
		int price;
		cin >> color[i] >> price;

		if (price <= K) {
			for (int j = i; j > t; j -- ) {
				s[color[j]] ++ ;
			}
			t = i;
			res += s[color[i]] - 1;
		} else{
			res += s[color[i]];
		}
	}

	cout << res << "\n";

	return 0;
}