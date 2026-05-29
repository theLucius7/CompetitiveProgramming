#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using i64 = long long;
using namespace std;

const int N = 5e3 + 10, M = 1e4 + 10;
int n, m, k;
int w[N], v[N], dp[M][N];

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++ ) {
		cin >> w[i] >> v[i];
	}
	// for (int i = 1; i <= n; i ++ ) {
	// 	for (int j = k; j >= 1; j -- ) {
	// 		dp[m][j] = max(dp[m][j], dp[m][j - 1] + v[i]);
	// 	}
	// 	// for (int j = m; j >= w[i]; j -- ) {
	// 	// 	dp[j][0] = max(dp[j][0], dp[j - w[i]][0] + v[i]);
	// 	// }
	// }
	for (int i = 1; i <= n; i ++ ) {
		// for (int j = k; j >= 1; j -- ) {
		// 	dp[m][j] = max(dp[m][j], dp[m][j - 1] + v[i]);
		// }
		for (int j = m; j >= w[i]; j -- ) {
			dp[j][0] = max(dp[j][0], dp[j - w[i]][0] + v[i]);
		}
	}
	// for (int i = k; i >= 1; i -- ) {
	// 	dp[m][i] = max(dp[m][i], dp[m][i - 1]);
	// }
	cout << dp[m][0] << endl;

	return 0;
}