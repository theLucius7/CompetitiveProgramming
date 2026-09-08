#include <bits/stdc++.h>
#define int long long
using namespace std;
struct DSU {
    vector<int> f;

    DSU(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[y] = x;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
	string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1.size() != s2.size()) {
        cout << "NO\n";
        return;
    }
    if (s1.size() != s3.size()) {
        cout << "YES\n";
        return;
    }
    int n = s1.size();
    // cout << n << endl;
    DSU dsu(26);
    for (int i = 0; i < n; i ++ ) {
        int x = s1[i] - 'a';
        int y = s2[i] - 'a';
        dsu.merge(x, y);
    }
    for (int i = 0; i < n; i ++ ) {
        int x = s1[i] - 'a';
        int y = s3[i] - 'a';
        if (!dsu.same(x, y)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T = 1;
	std::cin >> T;
	while (T -- ) {
		solve();
	}
	
	return 0;
}