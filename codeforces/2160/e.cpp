#include <bits/stdc++.h>
using i64 = long long;

struct FastGridIO {
    // 读一行中恰好 m 个 0/1（允许有空格或无空格）
    static std::vector<int> read01Row(int m) {
        std::vector<int> row;
        row.reserve(m);
        while ((int)row.size() < m) {
            std::string tok;
            if (!(std::cin >> tok)) break;
            for (char c : tok) {
                if (c == '0' || c == '1') {
                    row.push_back(c - '0');
                    if ((int)row.size() == m) break;
                }
            }
        }
        return row;
    }
};

void solve() {
    int n, m;
    if (!(std::cin >> n >> m)) return;

    std::vector<std::vector<int>> G(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        auto row = FastGridIO::read01Row(m);
        if ((int)row.size() != m) return;
        G[i] = std::move(row);
    }

    bool transposed = false;
    // 若行数更大，则转置以减少行对 (u,d) 的数量
    if (n > m) {
        std::vector<std::vector<int>> T(m, std::vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                T[j][i] = G[i][j];
        G.swap(T);
        std::swap(n, m);
        transposed = true;
    }

    // 位集行表示
    int W = (m + 63) >> 6; // 64 位块数
    std::vector<std::vector<unsigned long long>> bits(n, std::vector<unsigned long long>(W, 0ULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (G[i][j]) {
            bits[i][j >> 6] |= (1ULL << (j & 63));
        }
    }

    // 答案矩阵：LLONG_MAX 表示尚未被任何矩形覆盖到
    const i64 INF = (i64)9e18;
    std::vector<std::vector<i64>> ans(n, std::vector<i64>(m, INF));

    // 每行一个“下一未赋值位置”的 DSU（跳表）
    std::vector<std::vector<int>> nxt(n, std::vector<int>(m + 1));
    auto find = [&](std::vector<int>& fa, int x) -> int {
        while (fa[x] != x) {
            fa[x] = fa[fa[x]];
            x = fa[x];
        }
        return x;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) nxt[i][j] = j;
    }
    i64 remaining = 1LL * n * m;

    // 主流程：按高度 h 从 2..n 扫；每个固定 h 的 (u,d) 对产生候选区间 [a,b]（相邻公共 1）
    // 将这些候选按宽度 w 升序排序 -> 面积 A = h*w 升序
    for (int h = 2; h <= n && remaining > 0; h++) {
        struct Ev { int w, a, b, u, d; }; // 宽度、列[a,b]、行[u,d]
        std::vector<Ev> evs;
        // 生成本高度的所有事件
        for (int u = 0; u + h - 1 < n; u++) {
            int d = u + h - 1;
            // 按位与
            std::vector<unsigned long long> common(W);
            for (int t = 0; t < W; t++) common[t] = bits[u][t] & bits[d][t];

            // 把置位的列取出来
            std::vector<int> pos;
            pos.reserve(64 * W);
            for (int blk = 0; blk < W; blk++) {
                unsigned long long x = common[blk];
                while (x) {
                    int bit = __builtin_ctzll(x);
                    int col = (blk << 6) + bit;
                    if (col < m) pos.push_back(col);
                    x &= (x - 1);
                }
            }
            if ((int)pos.size() < 2) continue;

            // 相邻列对形成最小宽度的候选矩形
            for (int t = 0; t + 1 < (int)pos.size(); t++) {
                int a = pos[t], b = pos[t + 1];
                int w = b - a + 1;          // l<r，宽度至少 2
                if (w >= 2) evs.push_back({w, a, b, u, d});
            }
        }

        if (evs.empty()) continue;
        std::sort(evs.begin(), evs.end(), [](const Ev& A, const Ev& B){
            if (A.w != B.w) return A.w < B.w;
            if (A.u != B.u) return A.u < B.u;
            if (A.d != B.d) return A.d < B.d;
            if (A.a != B.a) return A.a < B.a;
            return A.b < B.b;
        });

        // 处理事件（面积从小到大，因为 A = h * w，h 固定、w 升序）
        for (const auto& e : evs) {
            i64 area = 1LL * h * e.w;
            // 遍历行区间 [u..d]，用该矩形给尚未赋值的列 [a..b] 第一次赋值
            for (int i = e.u; i <= e.d; i++) {
                int j = find(nxt[i], e.a);
                while (j <= e.b) {
                    if (ans[i][j] == INF) {
                        ans[i][j] = area;
                        --remaining;
                    }
                    // 跳过 j
                    nxt[i][j] = find(nxt[i], j + 1);
                    j = nxt[i][j];
                }
            }
            if (remaining == 0) break;
        }
    }

    // 输出（若一格从未被任何合法矩形覆盖，则输出 0）
    if (transposed) {
        // 需要把 ans 转回原始形状
        std::vector<std::vector<i64>> B(m, std::vector<i64>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                B[j][i] = ans[i][j];
        // 现在原始是 (m 行, n 列)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                i64 v = B[i][j];
                if (v == INF) v = 0;
                std::cout << v << (j + 1 == n ? '\n' : ' ');
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                i64 v = ans[i][j];
                if (v == INF) v = 0;
                std::cout << v << (j + 1 == m ? '\n' : ' ');
            }
        }
    }
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
