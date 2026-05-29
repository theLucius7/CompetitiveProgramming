#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    if (!(cin >> n)) return 0;

    // A[i][j] = 路径 i->j 上结点编号的按位异或
    // 题目给上三角，这里补全为 n x n
    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    const int r = 1; // 任取根 1
    auto LCA = [&](int u, int v) -> int {
        // median(u, v, r) = A[u][v] ^ A[v][r] ^ A[r][u]
        return A[u][v] ^ A[v][r] ^ A[r][u];
    };

    vector<pair<int,int>> edges;
    edges.reserve(n - 1);

    for (int v = 1; v <= n; ++v) {
        if (v == r) continue;

        // r 一定是祖先，拿来当初始候选
        int parent = r;
        for (int u = 1; u <= n; ++u) if (u != v) {
            // u 是 v 的祖先当且仅当 LCA(u, v) == u
            if (LCA(u, v) == u) {
                // 若当前 parent 是 u 的祖先（LCA(parent, u) == parent），
                // 说明 u 更深，替换之
                if ((A[parent][u] ^ A[u][r] ^ A[r][parent]) == parent) {
                    parent = u;
                }
            }
        }
        edges.emplace_back(parent, v);
    }

    for (auto [u, v] : edges) {
        cout << u << ' ' << v << '\n';
    }
    return 0;
}
