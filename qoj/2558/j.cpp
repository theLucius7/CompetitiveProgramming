#include <bits/stdc++.h>
#define int long long
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 1e18;

struct Tree {
    int n;
    vector<vector<int>> val, ver, s;
    vector<vector<int>> ver;
    vector<int> lg, dep, mn1, mn2;
    Tree(int n) {
        this->n = n;
        ver.resize(n + 1);
        val.resize(n + 1, vector<int>(30));
        
        lg.resize(n + 1);
        dep.resize(n + 1);
        mn1.assign(n + 1, inf);
        mn2.assign(n + 1, inf);
        for (int i = 1; i <= n; i ++ ) {
            lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
        }
    }

    void add(int x, int y) {
        ver[x].push_back(y);
        ver[y].push_back(x);
    }

    void dfs(int x, int fa) {
        val[x][0] = fa;
        dep[x] = dep[fa] + 1;
        for (int i = 1; i <= lg[dep[x]]; i ++ ) {
            val[x][i] = val[val[x][i - 1]][i - 1];

        }
        for (auto y : ver[x]) {
            if (y != fa) {

                dfs(y, x);
            }
        }
    }
}

void solve() {
    
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


	return 0;
}