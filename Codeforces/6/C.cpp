#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve () {
	int n;
	cin >> n;
	
	vector <int> w(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> w[i];
	}
	
	int a = 0, b = n - 1;
	int suma = 0, sumb = 0;
	
	while (a <= b) {
		if (suma <= sumb) {
			suma += w[a ++ ];
		} else {
			sumb += w[b -- ];
		}
	}
	
	cout << a << " " << n - a << "\n";	
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();
	
	return 0;
}