#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
const int N = 1e5 + 10;
struct Node {
	int l, r;
	int g;
	int change, f;
}t[N * 4];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void pushup(int p) {
	t[p].g = gcd(t[p << 1].g, t[p << 1 | 1].g);
}

void lazy(int p, int c) {
	t[p].g = c;
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
	t[p] = {l, r, 0, 0, 0};
	if (l != r) {
		int mid = l + r >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		pushup(p);
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
		pushup(p);
	}
}

int query(int p, int l, int r, int x, int y) {
	if (l >= x && r <= y) {
		return t[p].g;
	} else {
		pushdown(p);
		int mid = l + r >> 1;
		int res = 0;
		if (x <= mid) {
			res = gcd(res, query(p << 1, l, mid, x, y));
		}
		if (mid + 1 <= y) {
			res = gcd(res, query(p << 1 | 1, mid + 1, r, x, y));
		}
		pushup(p);
		return res;
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	build(1, 1, n);
	set<int> s;
	int l = 1, r = 2;
	while (r <= n) {
		if (a[r] < a[r - 1]) {
			modify(1, 1, n, l, r - 1, r - l);
			s.insert(r - 1);
			l = r;
		}
		r ++ ;
	}
	s.insert(r - 1);
	vector<int> ans{query(1, 1, n, 1, n)};
	while (q -- ) {
		int x, v;
		cin >> x >> v;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		// modify(1, 1, n, x, x, v);
		auto it = s.lower_bound(x);
		auto next_it = s.upper_bound(*it);
		if (x == 1) {
			if (*it == x) {
				if (v <= a[x + 1]) {
					modify(1, 1, n, 1, *next_it, *next_it == n ? 0 : *next_it);
					s.erase(it);
				}
			} else {
				if (v > a[x + 1]) {
					modify(1, 1, n, 1, 1, 1);
					if (*it != n) {
						modify(1, 1, n, x + 1, *it, *it - 1);
					}
					s.insert(x);
				}
			}
		} else if (x == n) {
			if (it == s.begin()) {
				if (a[x - 1] > v) {
					modify(1, 1, n, 1, x - 1, x - 1);
					s.insert(x - 1);
				}
			} else {
				auto pre_it = prev(it);
				int r = *pre_it;
				if (r + 1 == x) {
					if (a[x - 1] <= v) {
						modify(1, 1, n, pre_it == s.begin() ? 1 : *prev(pre_it) + 1, x, 0);
						s.erase(pre_it);
					}
				} else {
					if (a[x - 1] > v) {
						modify(1, 1, n, *pre_it + 1, x - 1, (x - 1 - *pre_it));
						s.insert(x - 1);
					}
				}
			}
		} else {
			if (a[x - 1] > a[x] && a[x] > a[x + 1]) {
				if (a[x - 1] <= v) {
					if (v > a[x + 1]) {
						auto pre_it = prev(it);
						int l = pre_it == s.begin() ? 1 : *prev(pre_it) + 1;
						// cout << l << endl;
						modify(1, 1, n, l, x, x - l + 1);
						s.erase(pre_it);
					} else {
						auto pre_it = prev(it);
						int l = pre_it == s.begin() ? 1 : *prev(pre_it) + 1;
						// cout << l << endl;
						int r = *next_it;
						modify(1, 1, n, l, r, r - l + 1);
						s.erase(pre_it);
						s.erase(it);
					}
				} else {
					if (v > a[x + 1]) {

					} else {

					}
				}
			} else if (a[x] > a[x + 1]) {

			} else if (a[x - 1] > a[x]) {

			} else {

			}
			// if (a[x - 1] > v) {
			// 	if (a[x - 1] <= a[x]) {
			// 		int l = it == s.begin() ? 1 : *prev(it) + 1;
			// 		modify(1, 1, n, l, x - 1, x - l);
			// 		modify(1, 1, n, x, *it, *it - x + 1);
			// 	}
			// 	s.insert(x - 1);
			// } else {
			// 	if (it != s.begin()) {
			// 		auto pre_it = prev(it);
			// 		if (*pre_it + 1 == x) {
			// 			int l = pre_it == s.begin() ? 1 : *prev(pre_it) + 1;
			// 			// cout << l << endl;
			// 			modify(1, 1, n, l, x, x - l + 1);
			// 			s.erase(pre_it);
			// 		}
			// 	}
			// }
			// it = s.lower_bound(x);
			// if (v > a[x + 1]) {
			// 	if (a[x] <= a[x + 1]) {
			// 		int r = *it;
			// 		modify(1, 1, n, x, x, 1);
			// 		modify(1, 1, n, x + 1, *it, *it - x);
			// 	}
			// 	s.insert(x);
			// } else {
			// 	cout << "00" << *it << endl;
			// 	if (*it == x) {
			// 		int l = it == s.begin() ? 1 : *prev(it) + 1;
			// 		int r = *next_it;
			// 		cout << "[ " << r << " ]\n";
			// 		modify(1, 1, n, l, r, r - l + 1);
			// 		s.erase(it);
			// 	}
			// }
		}
		// cout << 1 << "\n";
		// return;
		for (auto x : s) {
			cout << x << " ";
		}
		cout << endl;
		ans.push_back(t[1].g);
		a[x] = v;
	}

	for (auto x : ans) {
		cout << x << endl;
	}
}

int main() {

	int T;
	std::cin >> T;
	while (T -- ) {
		solve();
	}
	

	return 0;
}