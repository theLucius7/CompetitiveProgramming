#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};
constexpr int inf = 1E18;

struct Tag {
    int A = 0, C = 0;
    void apply(const Tag &t) & {
        if (t.A == 0 && t.C == 0) {
            return;
        }
        A += t.A;
        C = t.C;
    }
};

struct Info {
    int A = 0, C = -inf;
    void apply(const Tag &t) & {
        if (t.A == 0 && t.C == 0) {
            return;
        }
        A += t.A;
        C = t.C;
        if (A == 0) {
            C = -inf;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.A + b.A, std::max(a.C, b.C - a.A)};
}

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N), B(N);
    std::vector<int> vb;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        vb.push_back(B[i]);
    }

    std::vector<std::array<int, 3>> qrys(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> qrys[i][0] >> qrys[i][1] >> qrys[i][2];
        qrys[i][1]--;
        if (qrys[i][0] == 2) {
            vb.push_back(qrys[i][2]);
        }
    }

    std::sort(vb.begin(), vb.end());
    vb.erase(std::unique(vb.begin(), vb.end()), vb.end());


    int n = vb.size();
    LazySegmentTree<Info, Tag> t(n + 10);

    auto geti = [&](int x) {
        return std::lower_bound(vb.begin(), vb.end(), x) - vb.begin();
    };  

    for (int i = 0; i < N; i++) {
        t.rangeApply(geti(B[i]), geti(B[i]) + 1, {A[i], B[i]});
    }

    for (auto [op, i, x] : qrys) {
        if (op == 1) {
            t.rangeApply(geti(B[i]), geti(B[i]) + 1, {-A[i], B[i]});
            A[i] = x;
            t.rangeApply(geti(B[i]), geti(B[i]) + 1, {A[i], B[i]});
            auto ans = t.rangeQuery(0, n + 5);
            std::cout << ans.A + ans.C << "\n";
        } else {
            t.rangeApply(geti(B[i]), geti(B[i]) + 1, {-A[i], B[i]});
            B[i] = x;
            t.rangeApply(geti(B[i]), geti(B[i]) + 1, {A[i], B[i]});
            auto ans = t.rangeQuery(0, n + 5);
            std::cout << ans.A + ans.C << "\n";
        }
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
