#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;

void solve() {
	i64 n,m;
	std::cin >> n >> m;

	std::cout << (n + m + 1) / 2 << "\n";
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