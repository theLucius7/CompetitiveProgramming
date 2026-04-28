#include <bits/stdc++.h>

using i64 = long long;

int query(int op, int l, int r) {
    std::cout << op << " " << l << " " << r << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

void solve() {
    int n;
    std::cin >> n;

    int len = query(2, 1, n) - query(1, 1, n);

    int lo = 1, hi = n + 1;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (query(2, 1, m) > query(1, 1, m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }

    std::cout << "! " << lo << " " << lo + len - 1 << std::endl;
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