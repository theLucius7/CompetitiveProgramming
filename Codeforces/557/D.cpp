// LUOGU_RID: 93804633
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1E5 + 10, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N], cnt[3];


void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs (int u, int c) {
	color[u] = c;
	cnt[c] ++ ;

	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (!color[j]) {
			if (!dfs (j, 3 - c)) {
				return false;
			}
		} else if (color[j] == c) {
			return false;
		}
	}

	return true;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	if (m == 0) {
		cout << "3 " << 1LL * n * (n - 1) * (n - 2) / 6 << "\n";
		return 0;
	}

	memset (h, -1, sizeof h);

	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}

	bool flag = false;
	i64 ans1 = 0, ans2 = 0;

	for (int i = 1; i <= n; i ++ ) {
		if (!color[i]) {
			cnt[1] = cnt[2] = 0;

			if (!dfs (i, 1)) {
				cout << "0 1\n";
				return 0;
			}

			if (cnt[1] + cnt[2] >= 3) {
				flag = true;
				ans1 += 1LL * cnt[1] * (cnt[1] - 1) / 2 + 1LL * cnt[2] * (cnt[2] - 1) / 2; 
			} else if (cnt[1] + cnt[2] == 2 && !flag) {
				ans2 += n - 2;
			}
		}
	}

	if (flag) {
		cout << "1 " << ans1 << "\n";
	} else {
		cout << "2 " << ans2 << "\n";
	}

	return 0;
}