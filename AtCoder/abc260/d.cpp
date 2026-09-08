#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int a[N];
int ne[N], cnt[N];
int ans[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	memset (ne, -1, sizeof ne);

	set <int> s;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];

		auto it = s.lower_bound (a[i]);

		if (it == s.end ()) {
			if (m == 1) {
				ans[a[i]] = i;
			} else {
				s.insert (a[i]);
				cnt[a[i]] = 1;
			}
		} else {
			ne[a[i]] = *it;
			cnt[a[i]] = cnt[*it] + 1;
			
			s.erase (it);
			
			if (cnt[a[i]] == m) {
				for (int j = a[i]; ~j; j = ne[j]) {
					ans[j] = i;
				}
				continue;
			}

			s.insert (a[i]);
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		cout << (ans[i] ? ans[i] : -1) << "\n";
	}

	return 0;
}