#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < m; i++) {
        pq.push(0);
    }

    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int x = pq.top();
        pq.pop();
        ans += a[i] + x;
        pq.push(a[i] + x);
    }
    std::cout << ans << "\n";



    return 0;
}
