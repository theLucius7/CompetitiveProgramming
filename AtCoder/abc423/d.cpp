#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = LLONG_MAX;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    i64 K;
    std::cin >> N >> K;

    std::vector<i64> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i] >> C[i];
    }


    std::vector<i64> ans(N, -1);
    std::queue<int> q;
    std::priority_queue<std::pair<i64, i64>, std::vector<std::pair<i64, i64>>, std::greater<std::pair<i64, i64>>> pq;

    i64 t = 0;
    int p = 0;
    i64 inside = 0;

    while (p < N || !q.empty() || !pq.empty()) {
        bool ok = false;
        while (!q.empty() && inside + C[q.front()] <= K) {
            int u = q.front(); q.pop();
            ans[u] = t;
            inside += C[u];
            pq.emplace(t + B[u], C[u]);
            ok = true;
        }


        if (ok) {
        	continue;
        }


        i64 min = INF;
        if (p < N) {
        	min = std::min(min, A[p]);
        }
        if (!pq.empty()) {
        	min = std::min(min, pq.top().first);
        }

        if (min == INF) {
        	break;
        }

        t = min;
        while (!pq.empty() && pq.top().first == t) {
            inside -= pq.top().second;
            pq.pop();
        }
        while (p < N && A[p] == t) {
            q.push(p++);
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << "\n";
    }


    return 0;
}
