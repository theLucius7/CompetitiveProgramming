#include <bits/stdc++.h>

using i64 = long long;

struct Info {
    i64 sum = 0;
    int mn = 0;
    int max = 0;
    int len = 0;

    Info() {}
    Info(i64 _sum, int _mn, int _max, int _len) : sum(_sum), mn(_mn), max(_max), len(_len) {}

    friend Info operator+(const Info &a, const Info &b) {
        Info c;
        c.len = a.len + b.len;
        c.sum = a.sum + b.sum;
        c.mn  = std::min(a.mn, b.mn);
        c.max = std::max(a.max, b.max);
        return c;
    }
};

struct SegmentTree {
    int n;
    std::vector<int> tag;
    std::vector<char> tagZ;
    std::vector<Info> info;

    SegmentTree(int n_) : n(n_), tag(4 * n_, 0), tagZ(4 * n_, 0), info(4 * n_) {}

    void build(int p, int l, int r, const std::vector<int> &a) {
        if (r - l == 1) {
            info[p] = Info(a[l], a[l], a[l], 1);
            tag[p] = 0;
            tagZ[p] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m, a);
        build(2 * p + 1, m, r, a);
        pull(p);
        tag[p] = 0;
        tagZ[p] = 0;
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void add(int p, int v) {
        tagZ[p] = 0;
        tag[p] += v;
        info[p].sum += 1LL * v * info[p].len;
        info[p].mn += v;
        info[p].max += v;
    }

    void init(int p) {
        tagZ[p] = 1;
        tag[p] = 0;
        info[p].sum = 0;
        info[p].mn = 0;
        info[p].max = 0;
    }

    void push(int p) {
        if (tagZ[p]) {
            init(2 * p);
            init(2 * p + 1);
            tagZ[p] = 0;
        }
        if (tag[p] != 0) {
            add(2 * p, tag[p]);
            add(2 * p + 1, tag[p]);
            tag[p] = 0;
        }
    }

    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info(0, INT_MAX, INT_MIN, 0);
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            add(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            tag[p] = 0;
            tagZ[p] = 0;
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
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

    i64 calc(int p, int l, int r, int x, int y, int k) {
        if (l >= y || r <= x || info[p].max == 0) {
            return 0;
        }
        if (l >= x && r <= y) {
            if (info[p].max <= k) {
                i64 res = info[p].sum;
                init(p);
                return res;
            }
            if (info[p].mn >= k) {
                i64 res = 1LL * k * info[p].len;
                add(p, -k);
                return res;
            }
        }
        int m = (l + r) / 2;
        push(p);
        i64 res = 0;
        res += calc(2 * p, l, m, x, y, k);
        res += calc(2 * p + 1, m, r, x, y, k);
        pull(p);
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    SegmentTree seg(n);
    seg.build(1, 0, n, a);

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--;
        std::cout << seg.calc(1, 0, n, l, r, k) << "\n";
    }

    return 0;
}
