#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector <int> a(n);
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	
	vector <bool> f(m + 1);
	for (int i = 0; i < n; i ++ ) {
		if (a[i] <= m) f[a[i]] = true;
		for (int j = i + 1; j < n; j ++ ) {
			if (a[i] + a[j] <= m) f[a[i] + a[j]] = true;
			for (int k = j + 1; k < n; k ++ ) {
				if (a[i] + a[j] + a[k] <= m) f[a[i] + a[j] + a[k]] = true;
			}
		}
	}
	
	cout << count (f.begin (), f.end (), true) << "\n";
	
	return 0;
}