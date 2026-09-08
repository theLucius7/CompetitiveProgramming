#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    std::vector<std::array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        v[i] = {i + 1, a, b};
    }

    std::sort(v.begin(), v.end(), [&](auto x, auto y) {
        auto [idx, ax, bx] = x;
        auto [idy, ay, by] = y;
        if (ax != ay) {
            return ax < ay;
        } else {
            return bx > by;
        }
    });

    int min = 1E8, cnt = 0;
    std::vector<int> set;

    for (int i = n - 1; i >= 0; i--) {
        auto [id, a, b] = v[i];
        if (a != min) {
            if (b >= set.size()) {
                set.push_back(id);
                min = a;
                cnt = 1;
            }
        } else {
            if (b >= set.size() - cnt) {
                set.push_back(id);
                cnt++;
            }
        }
    }

    std::cout << set.size() << "\n";
    for (int i = 0; i < set.size(); i++) {
        std::cout << set[i] << " \n"[i == set.size() - 1]; 
    }


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}
