#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;

void solve () {
	int n, m;
	cin >> n >> m;
	
	vector <int> w(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> w[i];
	}
	
	map <string, int> mp;
	vector <string> s(m);
	
	for (int i = 0; i < m; i ++ ) {
		cin >> s[i];
		mp[s[i]] ++ ;
	}
	
	vector <int> a;
	
	for (auto i : mp) {
		a.push_back (i.y);
	}
	
	sort (w.begin (), w.end ());
	sort (a.begin (), a.end ());
	
	int minn = 0, maxn = 0;
	for (int i = 0; i < (int)a.size (); i ++ ) {
		minn += a[a.size () - i - 1] * w[i];
		maxn += a[a.size () - i - 1] * w[n - i - 1];
	}
	
	cout << minn << " " << maxn << "\n";
	
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}