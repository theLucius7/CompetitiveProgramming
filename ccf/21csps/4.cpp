#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

const int N = 1e5 + 10;

int n, m1, m2;
PII a[N], b[N];
bool st1[N], st2[N];
int s1[N], s2[N];

void calc (PII *t, int m, int *s) {
	priority_queue <PII, vector <PII>, greater <PII>> lq;
	priority_queue <int, vector <int>, greater <int>> wq;

	for (int i = 1; i <= n; i ++ ) {
		wq.push (i);
	}

	for (int i = 0; i < m; i ++ ) {
		while (lq.size () && t[i].x >= lq.top ().x) {
			wq.push (lq.top ().y);
			lq.pop ();
		}

		if (wq.size ()) {
			int item = wq.top ();
			wq.pop ();
			s[item] ++ ;
			lq.push ({t[i].y, item});
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		s[i] += s[i - 1];
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m1 >> m2;

	for (int i = 0; i < m1; i ++ ) {
		cin >> a[i].x >> a[i].y;
	}

	for (int i = 0; i < m2; i ++ ) {
		cin >> b[i].x >> b[i].y;
	}

	sort (a, a + m1);
	sort (b, b + m2);

	calc (a, m1, s1);
	calc (b, m2, s2);

	int res = 0;
	for (int i = 0; i <= n; i ++ ) {
		res = max (res, s1[i] + s2[n - i]);
	}

	cout << res << "\n";

	return 0;
}