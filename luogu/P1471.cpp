#include <bits/stdc++.h>

using i64 = long long;

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
};

struct Tag {
    long double add = 0;
    void apply(const Tag &t) & {
        add += t.add;
    }
};

struct Info {
    long double sum = 0;
    long double sumSq = 0;
    int len = 0;
    void apply(const Tag &t) & {
        sumSq += len * (t.add * t.add) + 2 * t.add * sum;
        sum += t.add * len;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.sum + b.sum, a.sumSq + b.sumSq, a.len + b.len};
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<long double> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<Info> init(N);
    for (int i = 0; i < N; i++) {
        init[i].sum = a[i];
        init[i].sumSq = a[i] * a[i];
        init[i].len = 1;
    }

    LazySegmentTree<Info, Tag> t(init);

    while (M--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x, y;
            long double k;
            std::cin >> x >> y >> k;
            x--, y--;
            t.rangeApply(x, y + 1, Tag{k});
        } else if (op == 2) {
            int x, y;
            std::cin >> x >> y;
            x--, y--;
            Info ans = t.rangeQuery(x, y + 1);
            std::cout << std::fixed << std::setprecision(4) << ans.sum / ans.len << "\n";
        } else {
            int x, y;
            std::cin >> x >> y;
            x--, y--;
            Info ans = t.rangeQuery(x, y + 1);
            std::cout << std::fixed << std::setprecision(4) << (ans.sumSq / ans.len - (ans.sum / ans.len) * (ans.sum / ans.len)) << "\n";
        }
    }


	return 0;
}