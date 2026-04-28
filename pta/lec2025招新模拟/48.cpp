#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n), pref(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    std::string s;
    std::cin >> s;

    std::vector<int> L, R;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            L.push_back(i);
        } else {
            R.push_back(i);
        }
    }


    int i = 0, j = R.size() - 1;
    i64 ans = 0;
    while (i < L.size() && j >= 0 && L[i] < R[j]) {
        ans += pref[R[j] + 1] - pref[L[i]];
        i++;
        j--;
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