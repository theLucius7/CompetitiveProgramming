#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        y--;
        adj[i].push_back(y);
    }

    int x;
    std::cin >> x;
    x--;

    std::cout << x + 1 << " ";
    while (adj[x][0] != -1) {
        std::cout << adj[x][0] + 1 << " ";
        x = adj[x][0];
    }

	return 0;
}