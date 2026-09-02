#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 510, inf = 1E9;

int n, m;
int d[N][N];

void floyd () {
    for (int k = 1; k <= n; k ++ ) {
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = inf;
            }
        }
    }

    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min (d[a][b], c);
        d[b][a] = min (d[b][a], c);
    }


    int k, t;
    std::cin >> k >> t;

    std::vector<int> D(k);
    for (int i = 0; i < k; i++) {
        std::cin >> D[i];
    }

    for (auto a : D) {
        for (auto b : D) {
            d[a][b] = min (d[a][b], t);
            d[b][a] = min (d[b][a], t);
        }
    }

    int q;
    std::cin >> q;

    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int a, b, t;
            std::cin >> a >> b >> t;
            d[a][b] = min(d[a][b], t);
            d[b][a] = min(d[b][a], t);
        } else if (op == 2) {
            int a;
            std::cin >> a;

            for (auto b : D) {
                d[a][b] = min (d[a][b], t);
                d[b][a] = min (d[b][a], t);
            }

            D.push_back(a);
        } else {
            i64 ans = 0;

            floyd ();
            for (int i = 1; i <= 500; i++) {
                for (int j = 1; j <= 500; j++) {
                    if (d[i][j] != inf) {
                        ans += d[i][j];
                    }
                }
            }

            std::cout << ans << "\n";
        }
    }

    return 0;
}

// 作者：Lucius7
// 链接：https://www.acwing.com/activity/content/code/content/4524961/
// 来源：AcWing
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。