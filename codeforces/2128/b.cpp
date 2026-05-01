#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int le = 0, ri = n - 1, t = 0;
    std::string ans;
    while(le < ri) {
        if (t) {
            if (a[le] < a[ri]) {
                le++;
                ans += "L";
            } else {
                ri--;
                ans += "R";
            }
        } else {
            if (a[le] > a[ri]) {
                le++;
                ans += "L";
            } else {
                ri--;
                ans += "R";
            }
        }
    t ^= 1;
    }
    std::cout << ans << "\n";
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
