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
            return ax > ay;
        } else {
            return bx > by;
        }
    });

    int min = 1E8, cnt = 0;
    std::vector<int> set;

    std::vector<int> u;
    int ans = 0;
    for (int i = 0; i < n;) {
        auto [id, a, b] = v[i];
        int j = i;
        int num = 0;
        while (j < n && v[j][1] == a) {
            int t = std::min(v[j][2], ans - num);
            if (j - i + 1 + t > ans) {
                ans = j - i + 1 + t;
                for (int k = i + num; k <= j; k ++ ) {
                    set.push_back(v[k][0]);
                }
                num = j - i + 1;
            }
            j ++ ;
        }
        i = j;
    }

    int m = set.size();
    std::cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        std::cout << set[m - 1 - i] << " \n"[i == ans - 1]; 
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