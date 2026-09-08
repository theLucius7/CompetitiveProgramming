#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct node {
	bool f;
	LL w, n;
};

LL n, x, y;
queue <node> a;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> x >> y;
	a.push ({1, n, 1});
	
	LL res = 0;
	while (a.size ()) {
		auto t = a.front ();
		a.pop ();
		
		if (t.f) {
			if (t.w >= 2) {
				a.push ({1, t.w - 1, 1 * t.n}), a.push ({0, t.w, x * t.n});
			}
		} else {
			if (t.w == 1) {
				res += t.n;
			} else if (t.w >= 2){
				a.push ({1, t.w - 1, 1 * t.n}), a.push ({0, t.w - 1, y * t.n});
			}
		}
	}
	
	cout << res;
	
	return 0;	
}