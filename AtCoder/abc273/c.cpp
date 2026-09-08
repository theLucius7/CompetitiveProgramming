#include <bits/stdc++.h>

using namespace std;

typedef long long i64;


void solve () {
	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	
	vector <int> b = a;
	
	sort (a.begin (), a.end (), greater <int> ());
				
	unordered_map <int, int> mp; 
	
	int last = a[0], cnt = 1;
	
	for (int i = 0; i < a.size (); i ++ ) {
		if (a[i] != last) {
			mp[a[i]] = cnt;
			last = a[i];
			cnt ++ ;
		}
	}
	
	vector <int> ans (n);
	
	for (int i = 0; i < n; i ++ ) {
		ans[mp[b[i]]] ++ ;
	}
	
	for (int i = 0; i < n; i ++ ) {
		cout << ans[i] << "\n";
	}
} 

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}