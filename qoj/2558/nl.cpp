#include <bits/stdc++.h>
#define int long long
using namespace std;

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    vector<int> s(n + 1);
    for (int i = 0; i < n; i ++ ) {
        s[i + 1] = s[i] + a[i];
    }
    vector<int> ans(n + 1);

    for (int i = n - 1; i >= 2; i -- ) {
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (s[i] - s[mid] > a[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        // cout << l << endl;
        if (s[i] - s[l] > a[i]) {
            while (!ans[i - l + 1]) {
                ans[i - l + 1] = s[i + 1] - s[l];
                l -- ;
            }
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


	return 0;
}