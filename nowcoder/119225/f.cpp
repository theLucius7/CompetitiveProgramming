#include <bits/stdc++.h>
using i64 = long long;

struct BIT {
    int n;
    std::vector<int> t;
    BIT(int n_ = 0) { init(n_); }
    void init(int n_) { n = n_; t.assign(n + 1, 0); }
    void add(int i, int v) {
        for (; i <= n; i += i & -i) t[i] += v;
    }
    int sumPrefix(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += t[i];
        return s;
    }
    int rangeSum(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

static inline int get_id(i64 x) {
    int e3 = (x % 9 == 0) ? 2 : ((x % 3 == 0) ? 1 : 0);
    int d5 = (x % 5 == 0) ? 1 : 0;   // 1 表示可被 5 整除
    int d11 = (x % 11 == 0) ? 1 : 0; // 1 表示可被 11 整除
    return e3 * 4 + d5 * 2 + d11;    // [0..11]
}

static inline i64 C2(i64 x) { return x * (x - 1) / 2; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    if (!(std::cin >> n >> q)) return 0;
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    // 12 类 BIT
    std::vector<BIT> ft(12, BIT(n));
    // 当前每个位置所属类别
    std::vector<int> id(n + 1);
    for (int i = 1; i <= n; i++) {
        id[i] = get_id(a[i]);
        ft[id[i]].add(i, 1);
    }

    while (q--) {
        int op; std::cin >> op;
        if (op == 1) {
            int x; i64 y; std::cin >> x >> y;
            // 删除旧类，加入新类
            ft[id[x]].add(x, -1);
            a[x] = y;
            id[x] = get_id(a[x]);
            ft[id[x]].add(x, +1);
        } else { // op == 2
            int l, r; std::cin >> l >> r;
            i64 cnt[12];
            i64 totalN = 0;
            for (int k = 0; k < 12; k++) {
                cnt[k] = ft[k].rangeSum(l, r);
                totalN += cnt[k];
            }
            i64 totalPairs = C2(totalN);

            // 汇总不同维度的计数
            // v3: (0,1,2+)
            i64 t0 = cnt[0] + cnt[1] + cnt[2] + cnt[3];
            i64 t1 = cnt[4] + cnt[5] + cnt[6] + cnt[7];
            i64 t2 = cnt[8] + cnt[9] + cnt[10] + cnt[11]; // 仅用于统计总数

            // not divisible by 5 / 11
            i64 S5 = cnt[0] + cnt[1] + cnt[4] + cnt[5] + cnt[8] + cnt[9];
            i64 S11 = cnt[0] + cnt[2] + cnt[4] + cnt[6] + cnt[8] + cnt[10];
            i64 S00 = cnt[0] + cnt[4] + cnt[8]; // 同时不被 5、11 整除

            // B3（3 的幂不足）：在全体中按 v3
            i64 B3 = C2(t0) + t0 * t1;

            // B5：都不被 5 整除
            i64 B5 = C2(S5);

            // B11：都不被 11 整除
            i64 B11 = C2(S11);

            // 交集：在相应子集中再按 v3 统计 (0,0) 与 (0,1)
            // 在 d5==0 的子集
            i64 t0_5 = cnt[0] + cnt[1];
            i64 t1_5 = cnt[4] + cnt[5];
            i64 B3B5 = C2(t0_5) + t0_5 * t1_5;

            // 在 d11==0 的子集
            i64 t0_11 = cnt[0] + cnt[2];
            i64 t1_11 = cnt[4] + cnt[6];
            i64 B3B11 = C2(t0_11) + t0_11 * t1_11;

            // 都不被 5、11 整除的子集
            i64 t0_00 = cnt[0];
            i64 t1_00 = cnt[4];
            i64 B3B5B11 = C2(t0_00) + t0_00 * t1_00;

            // B5∩B11：都不被 5、11 整除
            i64 B5B11 = C2(S00);

            i64 ans = totalPairs - (B3 + B5 + B11) + (B3B5 + B3B11 + B5B11) - B3B5B11;
            std::cout << ans << '\n';
        }
    }
    return 0;
}
