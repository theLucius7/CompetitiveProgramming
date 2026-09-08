#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		cin >> n;

		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i ++ ) {
			int x;
			cin >> x;

			string s;
			cin >> s;

			for (int j = 0; j < s.size (); j ++ ) {
				if (s[j] == 'U') {
					a[i] -- ; 
				} else {
					a[i] ++ ;
				}
			}

			cout << (a[i] % 10 + 10) % 10 << " \n"[i == n - 1];
		}
	}


	return 0;
}