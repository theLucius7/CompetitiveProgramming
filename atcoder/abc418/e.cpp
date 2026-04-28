#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// 规范化方向向量 (dx, dy)，无向边：让 dx>0 或 dx==0&&dy>0
static inline pair<int,int> norm_dir(long long dx, long long dy) {
    if (dx == 0 && dy == 0) return {0,0}; // 不会发生
    long long g = std::gcd(std::llabs(dx), std::llabs(dy));
    dx /= g; dy /= g;
    if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
    return {(int)dx, (int)dy};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    // 总线段数 M = N*(N-1)/2，约 2e6（N=2000）
    const int64 M = 1LL * N * (N - 1) / 2;

    // 方向键：pair<int,int>；中点键：pair<int,int>（使用坐标和，避免浮点）
    vector<pair<int,int>> dirs;
    vector<pair<int,int>> mids;
    dirs.reserve(M);
    mids.reserve(M);

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            auto d = norm_dir(1LL * X[j] - X[i], 1LL * Y[j] - Y[i]);
            dirs.push_back(d);
            // 中点用 (x_i + x_j, y_i + y_j) 作为哈希键（整数）
            mids.emplace_back(X[i] + X[j], Y[i] + Y[j]);
        }
    }

    auto count_pairs = [](auto &v) -> long long {
        sort(v.begin(), v.end());
        long long res = 0;
        for (size_t i = 0; i < v.size(); ) {
            size_t j = i + 1;
            while (j < v.size() && v[j] == v[i]) ++j;
            long long k = j - i;
            res += k * (k - 1) / 2; // C(k,2)
            i = j;
        }
        return res;
    };

    long long parallel_pairs = count_pairs(dirs); // 按方向分组的对数之和
    long long parallelograms = count_pairs(mids); // 按中点分组的对数之和

    // 至少一对平行边（包含平行四边形）
    long long ans = parallel_pairs - parallelograms;

    cout << ans << '\n';
    return 0;
}
