#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    std::array<std::string, 3> s;
    for (int i = 0; i < 3; i++) {
    	std::cin >> s[i];
    }

    std::string t, ans = "CCC";
    std::array<std::array<int, 3>, 3> vis{};
    auto dfs = [&](auto self, int i, int x, int y) -> void {
    	if (vis[x][y]) {
    		return;
    	}

    	t += s[x][y];
    	vis[x][y] = 1;

    	if (i == 2) {
    		ans = std::min(ans, t);
    	} else {
    		for (int nx = 0; nx < 3; nx++) {
    			for (int ny = 0; ny < 3; ny++) {
    				if (std::abs(nx - x) <= 1 &&  std::abs(ny - y) <= 1) {
    					self(self, i + 1, nx, ny);
    				}
    			}
    		}
    	}

    	t.pop_back();
    	vis[x][y] = 0;
    };

    for (int x = 0; x < 3; x++) {
    	for (int y = 0; y < 3; y++) {
    		dfs(dfs, 0, x, y);
    	}
    }

    std::cout << ans << "\n";

	return 0;
}