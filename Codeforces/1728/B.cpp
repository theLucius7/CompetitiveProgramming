#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		cin >> n;

		unordered_map <string, int> mpa;
		unordered_map <string, int> mpb;

		vector <string> a(n);
		vector <string> b(n);

		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
			mpa[a[i]] ++ ;
		}
		for (int i = 0; i < n; i ++ ) {
			cin >> b[i];
			mpb[b[i]] ++ ;
		}

		sort (a.begin (), a.end ());
		sort (b.begin (), b.end ());

		int res = 0;
		for (int i = 0; i < n; i ++ ) {
			if (a[i].size () >= 2) {
				if (mpb.count (a[i])) {
					mpb[b[i]] -- ;
					mpa[a[i]] -- ;
				} else {
					mpa[a[i]] -- ;
					a.push_back (to_string (a[i].size ()));
					mpa[to_string (a[i].size ())] ++ ;
					res ++ ;
				}
			}
		}

		for (int i = 0; i < n; i ++ ) {
			if (b[i].size () >= 2) {
				if (mpb.count (b[i])) {
					mpb[b[i]] -- ;
					b.push_back (to_string (b[i].size ()));
					mpb[to_string (b[i].size ())] ++ ;
					res ++ ;
				}
			}
		}

		for (auto sa : a) {
			if (sa.size () == 1) {
				if (!mpb[sa]) {
					if (sa == "1") {
						res ++ ;
					} else {
						if (mpb.count ("1")) {
							res ++ ;
							mpb["1"] -- ;
						} else {
							res += 2;
						}
					}
				} else {
					mpb[sa] -- ;
				}
			}
		}

		cout << res << "\n";
	}

	return 0;
}