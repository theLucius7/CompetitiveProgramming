#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <int> w(10);
	for (int i = 0; i < 10; i ++ ) {
		cin >> w[i];
	}

	vector <int> f(1e6 + 10);
	for (int i = 0; i <= 9; i++){
		for (int l = w[i]; l <= n; l++)
      	if (f[l - w[i]] * 10 + i > f[l]) f[l] = f[l - w[i]] * 10 + i; 
	}

	cout << f[n];
   



	return 0;
}