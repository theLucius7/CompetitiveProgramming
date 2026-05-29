#include <bits/stdc++.h>
#define int long long
using i64 = long long;
typedef long long LL;
using namespace std;
const int inf = 1e18;

struct Node {
    int l, r;
    int change, f;
    int sum, add;
    int Max, Min;
};

struct SegmentTree {
    vector<Node> t;
    vector<int> w;
    
    SegmentTree(int n) {
        t.resize(n * 4 + 1);
        w.resize(n + 1);
        build(1, 1, n);
    }
    SegmentTree(vector<int> in) {
        int n = in.size() - 1;
        t.resize(n * 4);
        w.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            w[i] = in[i];
        }
        build(1, 1, n);
    }

    void pushup(int p) {
        t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
        t[p].Max = max(t[p << 1].Max, t[p << 1 | 1].Max);
        t[p].Min = min(t[p << 1].Min, t[p << 1 | 1].Min);
    }

    void changelazy(int p, int v) {
        t[p].sum = v;
        t[p].Max = v;
        t[p].Min = v;
        t[p].change = v;
        t[p].f = 1;
        t[p].add = 0;
    }

    void addlazy(int p, LL v) {
        t[p].sum += v * (t[p].r - t[p].l + 1);
        t[p].Max += v;
        t[p].Min += v;
        t[p].add += v;
    }

    void pushdown(int p, int l, int r) {
        int mid = l + r >> 1;
        if (t[p].f) {
            changelazy(p << 1, t[p].change);
            changelazy(p << 1 | 1, t[p].change);
            t[p].f = 0;
        }
        if (t[p].add) {
            addlazy(p << 1, t[p].add);
            addlazy(p << 1 | 1, t[p].add);
            t[p].add = 0;
        }
    }

    void build(int p, int l, int r) {
        t[p] = {l, r, 0, 0, 0, 0, -inf, inf};
        if (l == r) {
            t[p].sum = t[p].Max = t[p].Min = w[l];
        } else {
            int mid = l + r >> 1;
            build(p << 1, l, mid);
            build(p << 1 | 1, mid + 1, r);
            pushup(p);
        }
        // cout << t[p].sum << "sum\n";
    }

    void change(int p, int x, int y, int l, int r, int v) {
        if (l >= x && r <= y) {
            changelazy(p, v);
        } else {
            pushdown(p, l, r);
            int mid = l + r >> 1;
            if (x <= mid) {
                change(p << 1, x, y, l, mid, v); 
            }
            if (mid + 1 <= y) {
                change(p << 1 | 1, x, y, mid + 1, r, v);
            }
            pushup(p);
        }
    }

    void modify(int p, int x, int y, int l, int r, int v) {
        if (l >= x && r <= y) {
            addlazy(p, v);
        } else {
            pushdown(p, l, r);
            int mid = l + r >> 1;
            if (x <= mid) {
                modify(p << 1, x, y, l, mid, v); 
            }
            if (mid + 1 <= y) {
                modify(p << 1 | 1, x, y, mid + 1, r, v);
            }
            pushup(p);
        }
    }

    int querySum(int p, int x, int y, int l, int r) {
        if (l >= x && r <= y) {
            return t[p].sum;
        } else {
            pushdown(p, l, r);
            LL ans = 0;
            int mid = l + r >> 1;
            if (x <= mid) {
                ans += querySum(p << 1, x, y, l, mid);
            }
            if (mid + 1 <= y) {
                ans += querySum(p << 1 | 1, x, y, mid + 1, r);
            }
            return ans;
        }
    }

    int search(int p, int l, int r, int s) {
    	if (l == r) {
    		return l;
    	}
    	int mid = l + r >> 1;
    	if (t[p << 1].sum >= s) {
    		return search(p << 1, l, mid, s);
    	} else {
    		return search(p << 1 | 1, mid + 1, r, s - t[p << 1].sum);
    	}
    }
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	vector<int> x(m + 1), t(m + 1);
	for (int i = 1; i <= m; i ++ ) {
		cin >> x[i] >> t[i];
	}
	vector<int> nxt(m + 1), suf(n + 1);
	for (int i = m; i >= 1; i -- ) {
		nxt[i] = suf[t[i]];
		suf[t[i]] = i;
	}
	vector<int> init(m + 1);
	int sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (!suf[i]) {
			sum += a[i];
		} else {
			init[suf[i]] = a[i];
		}
	}
	// cout << sum << "\n";
	SegmentTree seg(init);

	for (int i = 1; i <= m; i ++ ) {
		i64 s = seg.querySum(1, i, m, 1, m);
		if (s <= x[i] - x[i - 1]) {
			if (s + sum <= x[i] - x[i - 1]) {
				cout << x[i - 1] + s + sum << "\n";
				return;
			} else {
				seg.change(1, i, m, 1, m, 0);
				
			}
		}
		if (nxt[i]) {
			seg.modify(1, nxt[i], nxt[i], 1, m, a[t[i]]);
		} else {
			sum += a[t[i]];
		}
	}
	cout << sum << "op\n";
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	cin >> T;
	while (T -- ) {
		solve();
	}

	return 0;
}