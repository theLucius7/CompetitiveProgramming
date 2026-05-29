#include <bits/stdc++.h>

using i64 = long long;

using namespace std;
const int N = 1e5+10;
int n,m;
std::vector<pair<int,int>> mp[N];
vector<int> ans;
int fa[N];
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

int uu,vv;
void dfs(int u,int ff,int v){



	if (u == v ) {
		std::sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			std::cout << ans[i] << " \n"[i == ans.size() - 1];
		}
		return ;
	}

	for (auto [y, z] : mp[u]) {
		if (y != ff ) {
			if((u == uu && vv == y) || (u == vv || uu == y)) continue;
			ans.push_back(z);
			dfs(y,u,v);
			ans.pop_back();
		}
	}
}
void solve() {
	cin >> n >> m;
	bool f = false;

	for(int i = 1 ; i <= n ; i++){
		mp[i].clear();
	}


	DSU dsu(n + 1);
	ans.clear();
	for(int i = 1 ; i<= m ; i++){
		int u,v;
		cin >> u >> v;
		mp[u].push_back(make_pair(v,i));
		mp[v].push_back(make_pair(u,i));
		// std::cout << u << " " << v << "\n";
		
		if(!dsu.merge(u,v) && !f){
			ans.push_back(i);
			uu = u,vv = v;
			dfs(u,0,v);
			f = true;
		}
		else{
			
			continue;
		}
	}
	if(f){
		// std::cout << ans.size() << " \n";
		
		return;
	}
	cout << -1 << "\n";
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}