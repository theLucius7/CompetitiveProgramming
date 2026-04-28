#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n, m;
	cin >> n >> m;

	vector <vector <int> > adj(n + 1);
	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back (b);
		adj[b].push_back (a);
	}	

	for (int i = 1; i <= n; i ++ ) {
		vector <int> res = adj[i];
		sort (res.begin (), res.end ());
		cout << res.size () << " \n"[res.size () == 0];
		for (int i = 0; i < res.size (); i ++ ) {
			cout << res[i] << " \n"[i == res.size () - 1];
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve ();

	return 0;
}