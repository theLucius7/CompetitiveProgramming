#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 pre = 0, suf = 0;
    std::vector<int> cnt(2);
    for (int i = 0; i < n; i++) {
        pre += a[i];
        if (pre <= (k + 1) / 2) {
            cnt[0]++;
        } else {
            a[i] -= ((k + 1) / 2 - pre + a[i]);
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suf += a[i];
        if (suf <= k / 2) {
            cnt[1]++;
        } else {
            break;
        }
    }

    std::cout << std::min(cnt[0] + cnt[1], n) << "\n";
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