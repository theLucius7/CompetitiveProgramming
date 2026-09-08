#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set <int> s;
	vector <int> cnt(N + 1);
	for (int i = 0; i < n; i ++ ) {
		int x;
		cin >> x;
		s.insert (x);
		cnt[x] ++ ;
	}

	LL res = 0;
	for (auto x : s ) {
		for (auto y : s ) {
			if (x * y > N) break;
			if (x == y) {
				res += (LL)cnt[x] * cnt[y] * cnt[x * y];
			} else {
				res += (LL)cnt[x] * cnt[y] * cnt[x * y];
			}
		}
	}

	cout << res << "\n";

	return 0;
}