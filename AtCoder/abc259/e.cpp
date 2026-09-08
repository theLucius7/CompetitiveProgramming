#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 2e5 + 10;

typedef pair <int, int> PII;

int n, m;
vector <PII> v[N];
unordered_map <int, int> maxe;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i ++ ) {
		cin >> m;
		for (int i = 0; i < m; i ++ ) {
			int p, e;
			cin >> p >> e;
			v[i].push_back ({p, e});
			if (!maxe.count (p)) {
				maxe[p] = e;
			} else {
				maxe[p] = max (maxe[p], e);
			}
		}
	}

	int res = 0;
	bool no = false;

	for (int i = 0; i < n; i ++ ) {
		bool ok = false;

		for (auto a : v[i]) {
			int p = a.x, e = a.y;
			if (e == maxe[p]) {
				ok = true;
			}
		}

		res += ok;
		no |= !ok;
	}

	res += no;

	cout << res << "\n";

	return 0;
}