#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int t = sqrt(n);
	for (int i = 3; i <= t; i ++ ) {
		if (n % i == 0) {
			cout << n / i << endl;
			return;
		}
	}
	if (n % 2 == 0) {
		cout << "2\n";
	} else {
		cout << "1\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T -- ) {
		solve();
	}

	return 0;
}