#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int N, K, X;
    std::cin >> N >> K >> X;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    std::vector<std::string> v;
    auto dfs = [&](auto self, std::string t, int u) -> void {
        if (u == K) {
           v.push_back(t);
          return;
        }
        for (int i = 0; i < N; ++i) {
            self(self, t + S[i], u + 1);
        }
    };
    
    dfs(dfs, "", 0);

    std::sort(v.begin(), v.end());

    std::cout << v[X - 1] << "\n";
   
	return 0;
}