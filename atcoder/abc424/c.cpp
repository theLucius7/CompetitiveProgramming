#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);

    std::vector<bool> learned(n);
    std::queue<int> q;

    for (int i = 0; i < n; i++) {
        int A, B;
        std::cin >> A >> B;
        if (A == 0 && B == 0) {
            learned[i] = true;
            q.push(i);

        } else {
            A--, B--;
            adj[A].push_back(i);
            adj[B].push_back(i);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!learned[v]) {
                learned[v] = true;
                q.push(v);

            }
        }
    }

    std::cout << std::count(learned.begin(), learned.end(), true) << "\n";


    return 0;
}