#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
const int N = 1e5 + 10;
struct Node {
	int l, r;
	int change, f;
}t[N * 4];

void lazy(int p, int c) {
	t[p].change = c;
	t[p].f = 1;
}

void pushdown(int p) {
	if (t[p].f) {
		lazy(p << 1, t[p].change);
		lazy(p << 1 | 1, t[p].change);
		t[p].f = 0;
	}
}

void build(int p, int l, int r) {
	t[p] = {l, r, 0, 0};
	if (l != r) {
		int mid = l + r >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
	}
}

void modify(int p, int l, int r, int x, int y, int c) {
	if (l >= x && r <= y) {
		lazy(p, c);
	} else {
		pushdown(p);
		int mid = l + r >> 1;
		if (x <= mid) {
			modify(p << 1, l, mid, x, y, c);
		}
		if (mid + 1 <= y) {
			modify(p << 1 | 1, mid + 1, r, x, y, c);
		}
	}
}

int query(int p, int l, int r, int x) {
	if (l == x && r == x) {
		return t[p].change;
	} else {
		pushdown(p);
		int mid = l + r >> 1;
		if (x <= mid) {
			return query(p << 1, l, mid, x);
		} else {
			return query(p << 1 | 1, mid + 1, r, x);
		}
	}
}

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;

	build(1, 1, m);
	int cur = -1;
	std::vector<i64> sum(m);
	int p = m;
	while (q--) {
		int op;
		std::cin >> op;
		

		if (op == 1) {
			int x;
			std::cin >> x;
			cur = x;
			modify(1, 1, m, 1, m, 0);
			p = m;
		} else if (op == 2) {
			int id, x;
			std::cin >> id >> x;
			if (x == cur) {
				if (!query(1, 1, m, id)) {
					modify(1, 1, m, id, id, 1);
					sum[id - 1] += p;
					p--;
				}	
			}
		} else {
			int id, x;
			std::cin >> id >> x;
			if (x == cur) {
				if (!query(1, 1, m, id)) {
					modify(1, 1, m, id, id, 1);
				}	
			}
		}
	}

	std::vector<std::pair<i64, int>> ans;
	for (int i = 0; i < m; i++) {
		ans.push_back({sum[i], i + 1});
	}
	std::sort(ans.begin(), ans.end(), [&](std::pair<i64, int> a, std::pair<i6, int> b) {
		if (a.first != b.first) {
			return a.first > b.first;
		}
		return a.second < b.second;
	});

	for (int i = 0; i < m; i++) {
		std::cout << ans[i].second << " " << ans[i].first << "\n";
	}
}

int main() {

	int t;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
	

	return 0;
}