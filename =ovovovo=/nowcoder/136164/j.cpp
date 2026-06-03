#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

#define int long long

constexpr int inf = 1E17;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }



    int mxb = *std::max_element(b.begin(), b.end()), mnb = *std::min_element(b.begin(), b.end());
    if (mxb > *std::max_element(a.begin(), a.end()) || mnb < *std::min_element(a.begin(), a.end())) {
        std::cout << -1 << "\n";
        return;
    }

    if (N == 2 && mxb == *std::max_element(a.begin(), a.end()) && mnb == *std::min_element(a.begin(), a.end()) && a[0] != b[0]) {
        std::cout << -1 << "\n";
    }

    int mxa = -1, idmx = 0;
    int mna = inf, idmn = 0;
    for (int i = 0; i < N; i++) {
        if (b[i] == mxb) {
            if (mxa < a[i]) {
                mxa = a[i];
                idmx = i;
            }
        }
        if (b[i] == mnb) {
            if (mna > a[i]) {
                mna = a[i];
                idmn = i;
            }
        }
    }


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
