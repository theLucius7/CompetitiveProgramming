#include <bits/stdc++.h>

using i64 = long long;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

constexpr i64 inf = 1E18 + 1;

struct Info {
    int max;
};

Info operator+ (const Info &a, const Info &b) {
    return {std::max(a.max, b.max)};
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    std::vector<int> h;
    int x;
    while (std::cin >> x) {
        h.push_back(x);
    }

    SegmentTree<Info> t(5E4 + 10);
    t.modify(h[0], Info{1});
    for (int i = 1; i < h.size(); i++) {        
        t.modify(h[i], {t.rangeQuery(h[i], 5E4 + 1).max + 1});
    }
    std::cout << t.rangeQuery(0, 5E4 + 1).max << "\n";

    SegmentTree<Info> nt(5E4 + 10);
    nt.modify(h[0], Info{1});
    for (int i = 1; i < h.size(); i++) {        
        nt.modify(h[i], {nt.rangeQuery(0, h[i]).max + 1});
    }

    std::cout << nt.rangeQuery(0, 5E4 + 1).max << "\n";
    

	return 0;
}