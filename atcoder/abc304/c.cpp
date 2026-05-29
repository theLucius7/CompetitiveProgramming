#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, D;
    std::cin >> N >> D;

    std::vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    std::vector<bool> vis(N);
    std::queue<int> q;
    vis[0] = true;
    q.push(0);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        
        for (int j = 0; j < N; j++) {
            if (!vis[j] && (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <= D * D) {
                vis[j] = true;
                q.push(j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << (vis[i] ? "Yes" : "No") << "\n";
    }


    return 0;
}
