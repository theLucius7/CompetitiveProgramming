#include <bits/stdc++.h>
#define int long long
using i64 = long long;

using namespace std;

void solve() {
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A, B;
    std::cin >> A >> B;

    int bl[7] = {0, 0, 2, 3, 0, 5, 6};
    int re[7] = {0, 1, 0, 0, 4, 0, 0};

    for (int a = 1; a <= 6; a++) {
        for (int b = 1; b <= 6; b++) {
            for (int c = 1; c <= 6; c++) {
                int nb = bl[a] + bl[b] + bl[c];
                int nr = re[a] + re[b] + re[c];
                if (nb == B && nr == A) {
                    std::cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "No\n";

    return 0;
}