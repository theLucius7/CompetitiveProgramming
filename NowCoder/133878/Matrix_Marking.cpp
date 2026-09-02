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

struct Tag {
    int x = 0;
    void apply(const Tag &t) & {
        x = std::max(x, t.x);
    }
};

constexpr int inf = 1E10;

struct Info {
    int mx = -inf, mn = inf;
    void apply(const Tag &t) & {
        // x = std::max(x, t.x);
    }
};

Info operator+(const Info &a, const Info &b) {
    return {std::max(a.mx, b.mx), std::min(a.mn, b.mn)};
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> d(n + 1, std::vector<int> (m + 1));

    std::vector<std::vector<int>> g(n, std::vector<int>(m));
    std::map<int, std::vector<std::pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> g[i][j];
            mp[g[i][j]].push_back({i, j});
        }
    }

    for (auto &[_, v] : mp) {
        std::sort(v.begin(), v.end());
        
        std::set<std::pair<int, int>> s;
        s.insert(v[0]);
        int y = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].second < y) {
                s.insert(v[i]);
                y = v[i].second;
            }
        }

        s.insert(v.back());
        y = v.back().second;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i].second > y) {
                s.insert(v[i]);
                y = v[i].second;
            }
        }

        std::vector<std::pair<int, int>> vec;
        for (auto [x, y] : s) {
            vec.push_back({x, y});
        }

        std::sort(vec.begin(), vec.end(), [&](auto a, auto b) {
            return a.second < b.second;
        });

        LazySegmentTree<Info, Tag> t(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            t.modify(i, {vec[i].first, vec[i].first});
        }

        
        for (int i = 0; i + 1 < vec.size(); i++) {
            int ya = vec[i].second, yb = vec[i + 1].second;
            if (ya >= yb) {
                continue;
            }
            int xa = t.rangeQuery(0, i + 1).mn, xb = t.rangeQuery(i + 1, vec.size()).mx;

            if (xa < xb) {
                d[xb + 1][yb + 1]++;
                d[xb + 1][ya]--;
                d[xa][yb + 1]--;
                d[xa][ya]++;
            }
        }
    }

    std::vector<std::vector<int>> ans(n + 1, std::vector<int>(m + 1));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            ans[x + 1][y + 1] = d[x][y] + ans[x][y + 1] + ans[x + 1][y] - ans[x][y];
            std::cout << (ans[x + 1][y + 1] ? 1 : 0);
        }
        std::cout << "\n";
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
