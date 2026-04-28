#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = LLONG_MAX;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	i64 V;
	int T;
	std::cin >> n >> m >> V >> T;
	T--;

	std::vector<std::vector<std::pair<int, i64>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    
    std::vector<std::pair<int, int>> dis(n, {n + 1, -V + 1});

    using Key = std::pair<std::pair<int, int>, int>;
    std::priority_queue<Key, std::vector<Key>, std::greater<Key>> pq;
    std::vector<bool> vis(n);
    dis[T] = {1, -V};
    pq.push({dis[T], T});

    while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		int u = cur.second;
		if (vis[u]) {
			continue;
		}

		vis[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            i64 w = g[u][i].second;
            
            auto ns = dis[u];
            if (w + ns.second <= 0) {
            	ns.second += w;
            } else {
            	ns.first += 1;
            	ns.second = -(V - w);
            }

            if (dis[v] > ns) {
            	dis[v] = ns;
            	pq.push({dis[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
    	if (dis[i].first > n) {
    		std::cout << -1 << " \n"[i == n - 1];
    	} else {
    		std::cout << dis[i].first << " \n"[i == n - 1];
    	}
    }


	return 0;
}