#include <bits/stdc++.h>

using namespace std;

const int N = 21;

int a[N];
bool st[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		int maxn = 0, maxi = -1;

		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
			if (a[i] > maxn) {
				maxi = i;
				maxn = a[i];
			}
		}

		cout << maxi + 1 << "\n";

	}

	return 0;
}