#include <bits/stdc++.h>
#define int long long
using i64 = long long;
using namespace std;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::array<int, 4>> pos(n);
    std::vector<char> col(n);
    std::vector<std::string> s(n);


    std::map<std::pair<int, int>, char> ans;
    int last = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        if (s[i] == "Circle") {
            int x, y, r;
            std::cin >> x >> y >> r;
            pos[i] = {x, y, r, 0};
            char cc;
            std::cin >> cc;
            col[i] = cc;
        } else if (s[i] == "Rectangle") {
            std::pair<int, int> x, y;
            std::cin >> x.first >> y.first >> x.second >> y.second;
            pos[i] = {x.first, y.first, x.second, y.second};

            char cc;
            std::cin >> cc;
            col[i] = cc;

        } else {
            std::pair<int, int> x, y;
            std::cin >> x.first >> y.first >> x.second >> y.second;
            pos[i] = {x.first, y.first, x.second, y.second};
            for (int j = x.first; j <= x.second; j ++ ) {
            	for (int k = y.first; k <= y.second; k ++ ) {
            		ans[{j, k}] = '.';
            	}
            }
            // pos[i] = {x.first, x.second, y.first, y.second};

            // std::vector<std::vector<char>> g(y.first - x.first + 1, std::vector<char>(y.second - x.second + 1));
            // for (int xx = x.first; xx <= x.second; xx++) {
            //     for (int yy = y.first; yy <= y.second; yy++) {
                    
            //         for (int k = last; k < i; k++) {
            //             if (s[k] == "Circle") {
            //                 auto [xs, ys, rs, nnn] = pos[k];
            //                 if ((xx - xs) * (xx - xs) + (yy - ys) * (yy - ys) <= rs * rs) {
            //                     ans[{xx, yy}] = col[k];
            //                 }
            //             } else {
            //                 auto [xl, yl, xr, yr] = pos[k];
            //                 if (xl <= xx && xx <= xr && yl <= yy && yy <= yr) {
            //                     ans[{xx, yy}] = col[k];
            //                 }
            //             }
            //         }

            //         if (ans.contains({xx, yy})){
            //             g[xx - x.first][yy - y.first] = ans[{xx, yy}];
            //             // std::cout << "?";
            //         } else {
            //             g[xx - x.first][yy - y.first] = '.';
            //         }

            //         last = i + 1;
            //     }
            // }

            // for (int gi = 0; gi < y.first - x.first; gi++) {
            //     for (int gj = 0; gj < y.second - x.second; gj++) {
            //         std::cout << g[gi][gj] << " \n"[gj == y.second - x.second - 1];
            //     }
            // }
            
        }
    }

    for (int i = 0; i < n; i ++ ) {
        if (s[i] == "Circle") {
            auto [x, y, r, _] = pos[i];
            for (auto &item : ans) {
            	auto [p, q] = item.first;
            	if ((p - x) * (p - x) + (q - y) * (q - y) <= r * r) {
            		item.second = col[i];
            	}
            }
        } else if (s[i] == "Rectangle") {
            auto [a, b, c, d] = pos[i];
            for (auto &item : ans) {
            	auto [p, q] = item.first;
            	if (p >= a && p <= c && q >= b && q <= d) {
            		item.second = col[i];
            	}
            }
        } else {
        	auto [a, b, c, d] = pos[i];
            // for (auto &item : ans) {
            // 	auto [p, q] = item.first;
            // 	if (p >= a && p <= c && q >= b && q <= d) {
            // 		cout << item.second << " \n"[q == d];
            // 	}
            // }

        	// std::cout << a << " " << b << " " << c << " " << d << "\n";
            for (int y = d; y >= b; y--) {
            	for (int x = a; x <= c; x++) {
            		std::cout << ans[{x, y}];
            	}
            	std::cout << "\n";
            }

        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T -- ) {
        solve();
    }
    
    return 0;
}