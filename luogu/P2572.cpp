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

struct Tag {
	int x = -1;
	int r = 0;
    void apply(const Tag &t) & {
    	if (t.x != -1) {
    		x = t.x;
    		r = 0;
    	}
    	r ^= t.r;
    }
};

struct Info {
	int cnt0 = 0, cnt1 = 0;
	int maxl0 = 0, maxr0 = 0;
	int maxl1 = 0, maxr1 = 0;
	int max0 = 0, max1 = 0;
    void apply(const Tag &t) & {
    	if (t.x != -1) {
    		int sum = cnt0 + cnt1;
    		if (t.x == 0) {
    			cnt0 = sum, cnt1 = 0;
    			maxl0 = sum, maxr0 = sum;
    			maxl1 = 0, maxr1 = 0;
    			max0 = sum, max1 = 0;
    		} else {
    			cnt0 = 0, cnt1 = sum;
    			maxl0 = 0, maxr0 = 0;
    			maxl1 = sum, maxr1 = sum;
    			max0 = 0, max1 = sum;
    		}
    	}
    	if (t.r) {
    		std::swap(cnt0, cnt1);
    		std::swap(maxl0, maxl1);
    		std::swap(maxr0, maxr1);
    		std::swap(max0, max1);
    	}
    }
};

Info operator+(const Info &a, const Info &b) {
	Info c;
	c.cnt0 = a.cnt0 + b.cnt0, c.cnt1 = a.cnt1 + b.cnt1;
	c.maxl0 = (a.cnt1 == 0 ? a.maxl0 + b.maxl0 : a.maxl0), c.maxr0 = (b.cnt1 == 0 ? b.maxr0 + a.maxr0 : b.maxr0);
	c.maxl1 = (a.cnt0 == 0 ? a.maxl1 + b.maxl1 : a.maxl1), c.maxr1 = (b.cnt0 == 0 ? b.maxr1 + a.maxr1 : b.maxr1);
	c.max0 = std::max({a.max0, a.maxr0 + b.maxl0, b.max0});
	c.max1 = std::max({a.max1, a.maxr1 + b.maxl1, b.max1});
    return c;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Info> init(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	std::cin >> x;
    	if (x == 0) {
    		init[i] = {1, 0, 1, 1, 0, 0, 1, 0};
    	} else {
    		init[i] = {0, 1, 0, 0, 1, 1, 0, 1};
    	}
    }
    LazySegmentTree<Info, Tag> t(init);

    while (m--) {
    	int op;
    	std::cin >> op;

    	if (op == 0) {
    		int l, r;
    		std::cin >> l >> r;
    		t.rangeApply(l, r + 1, {0, 0});
    	} else if (op == 1) {
    		int l, r;
    		std::cin >> l >> r;
    		t.rangeApply(l, r + 1, {1, 0});
    	} else if (op == 2) {
    		int l, r;
    		std::cin >> l >> r;
    		t.rangeApply(l, r + 1, {-1, 1});
    	} else if (op == 3) {
    		int l, r;
    		std::cin >> l >> r;
    		std::cout << t.rangeQuery(l, r + 1).cnt1 << "\n";
    	} else {
    		int l, r;
    		std::cin >> l >> r;
    		std::cout << t.rangeQuery(l, r + 1).max1 << "\n";
    	}
    }

	return 0;
}