#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    std::vector<std::pair<int, int>>q, adj;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            std::cin >> a[i][j];
            a[i][j] = a[j][i];
            if(a[i][j] == (i ^ j)){
                adj.push_back({i, j});
                // adj[j].push_back(i);
            }
            if(a[i][j] == 0){
                q.push_back({i, j});
            }
        }
    }    
    for(auto [x, y] : adj){
        int f = 0;
        for(auto [u, v] : q){
            if((a[x][u] == (x ^ u) and a[v][y] == (y ^ v)) 
                or (a[x][v] == (x ^ v) and a[u][y] == (u ^ y))){
                f = 1;
                break;
            }
                
        }
        if(f == 0)std::cout << x << ' ' << y << '\n';

    }

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }


	return 0;
}