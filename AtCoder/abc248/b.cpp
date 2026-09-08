#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, k;
	cin >> a >> b >> k;
	
	int l = 0, r = b;
	
	while (l < r) {
		int mid = l + r >> 1;
		if (a * pow (k, mid) >= b) r = mid;
		else l = mid + 1;
	}
	
	cout << l << "\n";
	
	return 0;
}