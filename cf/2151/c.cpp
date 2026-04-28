#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
	int n;
    std::cin >> n;

    std::vector<i64> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
    	std::cin >> a[i];
    }

    std::vector<i64> diff(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) {
    	diff[i] = a[i + 1] - a[i];
    }

    std::vector<i64> W(2 * n, 0), pre0(2 * n, 0), pre1(2 * n, 0);
    for (int i = 1; i < 2 * n; i++) {
        W[i] = W[i - 1] + i * diff[i - 1];
        pre0[i] = pre0[i - 1] + ((i % 2 == 0) ? diff[i - 1] : 0);
        pre1[i] = pre1[i - 1] + ((i % 2 == 1) ? diff[i - 1] : 0);
    }

    std::vector<i64> R(n + 1);
    for (int j = 1; j <= n; j++) {
        R[j] = R[j - 1] + j * diff[2 * n - j - 1];
    }

    for (int i = 1; i <= n; i++) {
        i64 ans = 0;
        if (i < n) {
            ans += W[i];

            int l = i, r = 2 * n - i;
            if (r - l > 1) {
                if (i % 2 == 0) {
                	ans += 1LL * i * (pre0[r - 1] - pre0[l]) + 1LL * (i - 1) * (pre1[r - 1] - pre1[l]);
                } else {
                	ans += 1LL * i * (pre1[r - 1] - pre1[l]) + 1LL * (i - 1) * (pre0[r - 1] - pre0[l]);
                }
            }
            ans += R[i];
        } else {
            ans += W[n - 1];
            ans += R[n];
        }

        std::cout << ans << " \n"[i == n];
    }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}