#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<int>());

    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);

    std::vector<i64> ans(n + 1);
    int l = 0, r = n - 1;

    for ( ; l < r; ) {
        if (sum - a[l] > a[l]) {
            if (r - l >= 2) {
                ans[r - l + 1] = sum;
                sum -= a[r];
                r--;
            } else {
                break;
            }
        } else {
            // break;
            sum -= a[l];
            l++;
            if (r + 1 < n) {
                r++;
                sum += a[r];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
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