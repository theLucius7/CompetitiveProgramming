#include <bits/stdc++.h>

using i64 = long long;
using real = long double

struct Video {
    int id;
    int b;
    int c;
};

struct State {
    int prev_M;
    bool picked;
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<Video> v(n);
    for (int i = 0; i < n; +) {
        std::cin >> v[i].id >> v[i].b >> v[i].c;
    }

    double m0_f;
    int q;
    std::cin >> m0_f >> q;
    int m0 = std::round(m0_f * 100);

    std::vector<Video> g1, g2, g3;
    for (int i = 0; i < n; ++i) {
        if (v[i].c >= 4) {
            g1.push_back(v[i]);
        } else if (v[i].c == 3) {
            g2.push_back(v[i]);
        } else {
            g3.push_back(v[i]);
        }
    }

    std::sort(g1.begin(), g1.end(), [](const Video& a, const Video& b) {
        if (a.b != b.b) return a.b < b.b;
        return a.id < b.id;
    });
    std::sort(g2.begin(), g2.end(), [](const Video& a, const Video& b) {
        if (a.b != b.b) return a.b > b.b;
        return a.id < b.id;
    });
    std::sort(g3.begin(), g3.end(), [](const Video& a, const Video& b) {
        if (a.b != b.b) return a.b > b.b;
        return a.id < b.id;
    });

    std::vector<Video> all_v;
    for (auto& x : g1) all_v.push_back(x);
    for (auto& x : g2) all_v.push_back(x);
    for (auto& x : g3) all_v.push_back(x);

    std::vector dp(n + 1, std::vector(n + 1, std::vector<double>(101, -1.0)));
    std::vector parent(n + 1, std::vector(n + 1, std::vector<State>(101, {-1, false})));

    dp[0][0][m0] = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int m = 30; m <= 100; ++m) {
                if (dp[i][j][m] < -0.5) continue;

                if (dp[i + 1][j][m] < dp[i][j][m]) {
                    dp[i + 1][j][m] = dp[i][j][m];
                    parent[i + 1][j][m] = {m, false};
                }

                int next_m = m;
                if (all_v[i].c <= 2) {
                    next_m = std::max(30, m - 10);
                } else if (all_v[i].c == 3) {
                    next_m = m;
                } else {
                    next_m = std::min(100, m + 5);
                }

                double gain = all_v[i].b * (m / 100.0);
                if (dp[i + 1][j + 1][next_m] < dp[i][j][m] + gain) {
                    dp[i + 1][j + 1][next_m] = dp[i][j][m] + gain;
                    parent[i + 1][j + 1][next_m] = {m, true};
                }
            }
        }
    }

    double max_time = -1.0;
    int best_j = -1, best_m = -1;

    for (int j = q; j <= n; ++j) {
        for (int m = 30; m <= 100; ++m) {
            if (dp[n][j][m] > max_time) {
                max_time = dp[n][j][m];
                best_j = j;
                best_m = m;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2) << max_time << "\n";

    std::vector<int> path;
    int cur_j = best_j;
    int cur_m = best_m;
    for (int i = n; i > 0; --i) {
        if (parent[i][cur_j][cur_m].picked) {
            path.push_back(all_v[i - 1].id);
            cur_m = parent[i][cur_j][cur_m].prev_M;
            cur_j--;
        } else {
            cur_m = parent[i][cur_j][cur_m].prev_M;
        }
    }
    std::reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
