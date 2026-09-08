#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10;

int head, tail, e[N], ne[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;
	
	head = -1, idx = 0;
	
	vector <int> x(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> x[i];
	}

	sort (x.begin (), x.end ());
	for (int i = 0; i < n - 1; i ++ ) {
		e[i] = x[i], ne[i] = i + 1;
	}
	head = 0, tail = n - 1;
	
	int res = x[head];
	bool flag = true;
	while (flag) {
		x[0] += a;
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (x[mid] > x[0]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		if (l == n - 1) {
			flag = false;
		}
		if (l != 0) {
			head = 2;
		}
		
		
		x[n - 1] -= b;
		for (int i = n - 2; i >= 0; i -- ) {
			if (x[i] >= x[i + 1]) {
				swap (x[i], x[i + 1]);
			} else {
				break;
			}
			
			if (i == 0) {
				flag = false;
			}
		}
		
		res = max (res, x[head]);
	}
	
	cout << res << "\n";
	
	return 0;
}