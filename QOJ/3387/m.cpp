#include <bits/stdc++.h>

using i64 = long long;

const int MAXN = 200000 + 5;
const int MAXA = 1000000;

// 树结构
std::vector<int> g[MAXN];
int a_arr[MAXN], u_arr[MAXN], v_arr[MAXN];
int parentArr[MAXN], depthArr[MAXN], heavy[MAXN];
int headArr[MAXN], posArr[MAXN], subtreeSz[MAXN];
int tinArr[MAXN], toutArr[MAXN];

// 当前处理质数时：某个结点的指数 & 打过的时间戳
int e_at[MAXN], tag_at[MAXN];

int n;

// 质因数信息：对每个质数 p，存所有 (i, e_p(a_i))，i 是新长出的结点编号
std::vector<std::pair<int,int>> primeVec[MAXA + 1];
// c1 的质因数指数
int c1Exp[MAXA + 1];
// 标记哪些质数出现过
bool primeFlag[MAXA + 1];
std::vector<int> usedPrimes;

struct BIT {
    int n;
    std::vector<i64> bit;
    BIT(int n_ = 0) { init(n_); }
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
    void add(int i, i64 v) {
        for (int x = i; x <= n; x += x & -x) {
            bit[x] += v;
        }
    }
    i64 sum(int i) const {
        i64 r = 0;
        for (int x = i; x > 0; x -= x & -x) {
            r += bit[x];
        }
        return r;
    }
};

// HLD 求 LCA
int lca(int a, int b) {
    while (headArr[a] != headArr[b]) {
        if (depthArr[headArr[a]] > depthArr[headArr[b]]) {
            a = parentArr[headArr[a]];
        } else {
            b = parentArr[headArr[b]];
        }
    }
    return (depthArr[a] < depthArr[b]) ? a : b;
}

// 小整数幂：底数是质数 <= 1e6，指数很小（<= 20）
int pow_int(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c1;
    if (!(std::cin >> n >> c1)) {
        return 0;
    }

    // 清空树
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    a_arr[1] = c1;
    parentArr[1] = 0;

    for (int i = 2; i <= n; i++) {
        int ai, ui, vi;
        std::cin >> ai >> ui >> vi;
        a_arr[i] = ai;
        u_arr[i] = ui;
        v_arr[i] = vi;
        // 新结点 i 与 vi 连边
        g[i].push_back(vi);
        g[vi].push_back(i);
    }

    // ---------- 线性筛最小质因数 ----------
    std::vector<int> spf(MAXA + 1);
    std::vector<int> primes;
    for (int i = 2; i <= MAXA; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            i64 v = 1LL * i * p;
            if (v > MAXA) break;
            spf[v] = p;
            if (p == spf[i]) break;
        }
    }

    // ---------- 因式分解 c1 ----------
    usedPrimes.clear();
    {
        int x = c1;
        while (x > 1) {
            int p = spf[x];
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e++;
            }
            c1Exp[p] = e;
            if (!primeFlag[p]) {
                primeFlag[p] = true;
                usedPrimes.push_back(p);
            }
        }
    }

    // ---------- 因式分解每个 a_i ----------
    for (int i = 2; i <= n; i++) {
        int x = a_arr[i];
        while (x > 1) {
            int p = spf[x];
            int e = 0;
            while (x % p == 0) {
                x /= p;
                e++;
            }
            primeVec[p].push_back({i, e});
            if (!primeFlag[p]) {
                primeFlag[p] = true;
                usedPrimes.push_back(p);
            }
        }
    }

    // ---------- Heavy-Light Decomposition ----------
    // dfs1：迭代求 parent / depth / subtree / heavy
    {
        std::vector<int> order;
        order.reserve(n);
        std::vector<int> st;
        st.reserve(n);
        st.push_back(1);
        parentArr[1] = 0;
        depthArr[1] = 0;

        while (!st.empty()) {
            int x = st.back();
            st.pop_back();
            order.push_back(x);
            for (int y : g[x]) {
                if (y == parentArr[x]) continue;
                parentArr[y] = x;
                depthArr[y] = depthArr[x] + 1;
                st.push_back(y);
            }
        }
        for (int idx = (int)order.size() - 1; idx >= 0; idx--) {
            int x = order[idx];
            subtreeSz[x] = 1;
            heavy[x] = -1;
            int maxsz = 0;
            for (int y : g[x]) {
                if (y == parentArr[x]) continue;
                subtreeSz[x] += subtreeSz[y];
                if (subtreeSz[y] > maxsz) {
                    maxsz = subtreeSz[y];
                    heavy[x] = y;
                }
            }
        }
    }

    // dfs2：迭代展开重链，给每个点编号 pos / head，并得到 tin / tout
    {
        int curPos = 0;
        std::vector<std::pair<int,int>> st;
        st.reserve(n);
        st.push_back({1, 1});  // (start_node, head)

        while (!st.empty()) {
            auto [v, h] = st.back();
            st.pop_back();
            int x = v;
            int curHead = h;
            while (x != -1) {
                headArr[x] = curHead;
                posArr[x] = ++curPos;
                tinArr[x] = posArr[x];

                // 压入所有轻儿子，作为之后新重链的起点
                for (int y : g[x]) {
                    if (y == parentArr[x] || y == heavy[x]) continue;
                    st.push_back({y, y});
                }

                x = heavy[x];
            }
        }
        for (int x = 1; x <= n; x++) {
            toutArr[x] = posArr[x] + subtreeSz[x] - 1;
        }
    }

    // ---------- 按质数一维一维处理 ----------
    BIT bit(n + 1);
    int stamp = 0;
    std::vector<int> c(n + 1);
    c[1] = c1;
    for (int i = 2; i <= n; i++) c[i] = 1;

    for (int p : usedPrimes) {
        if (primeVec[p].empty() && c1Exp[p] == 0) continue;

        stamp++;
        std::vector<std::pair<int,int>> updates;
        updates.reserve(primeVec[p].size() * 2 + 2);

        // 把结点 1 上的指数先加到 Fenwick + e_at 中
        if (c1Exp[p] > 0) {
            int e = c1Exp[p];
            int x = 1;
            int L = tinArr[x];
            int R = toutArr[x];
            bit.add(L, e);
            bit.add(R + 1, -e);
            updates.push_back({L, e});
            updates.push_back({R + 1, -e});
            e_at[x] = e;
            tag_at[x] = stamp;
        }

        // 对所有 a_i 中含 p 的结点 i，按 i 递增顺序处理
        for (auto &pr : primeVec[p]) {
            int i = pr.first;
            int ea = pr.second; // e_p(a_i)

            int ui = u_arr[i];
            int vi = v_arr[i];
            int LCA = lca(ui, vi);

            i64 Fu = bit.sum(tinArr[ui]);
            i64 Fv = bit.sum(tinArr[vi]);
            i64 Fl = bit.sum(tinArr[LCA]);
            int eL = (tag_at[LCA] == stamp ? e_at[LCA] : 0);

            i64 S = Fu + Fv - 2 * Fl + eL; // 路径上所有点的该质数指数和

            int remain = 0;
            if (S < ea) {
                remain = ea - (int)S;
            } else {
                remain = 0;
            }

            if (remain > 0) {
                int x = i;
                int L = tinArr[x];
                int R = toutArr[x];
                bit.add(L, remain);
                bit.add(R + 1, -remain);
                updates.push_back({L, remain});
                updates.push_back({R + 1, -remain});
                e_at[x] = remain;
                tag_at[x] = stamp;

                c[i] *= pow_int(p, remain);
            }
        }

        // 恢复 Fenwick 到全零，以免影响下一个质数
        for (auto &pr : updates) {
            int pos = pr.first;
            int val = pr.second;
            bit.add(pos, -val);
        }
    }

    // ---------- 输出 ----------
    for (int i = 1; i <= n; i++) {
        std::cout << c[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}

