#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

using real = long double;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> P(n);
    for (int i = 0; i < n; i++) {
        std::cin >> P[i].first >> P[i].second;
    }

    for (int i = 2; i < n; i++) {
        if ((P[i].second - P[i - 1].second) * (P[i].first - P[i - 2].first) == (P[i].second - P[i - 2].second) * (P[i].first - P[i - 1].first)) {
            std::cout << "STRAIGHT";
        } else if (P[i - 1].first == P[i - 2].first) {
            if (P[i - 1].second > P[i - 2].second) {
                if (P[i].first < P[i - 1].first) {
                    std::cout << "LEFT";
                } else {
                    std::cout << "RIGHT";
                }
            } else {
                if (P[i].first < P[i - 1].first) {
                    std::cout << "RIGHT";
                } else {
                    std::cout << "LEFT";
                }
            }
        
        } else {
            real k = 1.L * (P[i - 1].second - P[i - 2].second) / (P[i - 1].first - P[i - 2].first);
            real b = P[i - 1].second - 1.L * k * P[i - 1].first;
            
            if (P[i - 1].first < P[i - 2].first) {
                if (P[i].second < k * P[i].first + b) {
                    std::cout << "LEFT";
                } else {
                    std::cout << "RIGHT";
                }   
            } else {
                if (P[i].second > k * P[i].first + b) {
                    std::cout << "LEFT";
                } else {
                    std::cout << "RIGHT";
                }   
            }
        }
        std::cout << " \n"[i == n - 1];
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
