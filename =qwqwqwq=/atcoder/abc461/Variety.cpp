#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, K, M;
    std::cin >> N >> K >> M;

    std::map<int, std::priority_queue<int>> mp;
    for (int i = 0; i < N; i++) {
        int C, V;
        std::cin >> C >> V;
        mp[C].push(V);
    }

    std::set<std::pair<int, int>> s;
    for (auto [k, v] : mp) {
        s.insert({v.top(), k});
    }

    i64 ans = 0;
    int cnt = 0;
    for (auto it = s.rbegin(); it != s.rend() && cnt < M; it++, cnt++) {
        auto [V, C] = *it;
        mp[C].pop();
        ans += V;
        // std::cout << "?\n";
    }

    std::multiset<int> ns;
    for (auto [k, v] : mp) {
        while (!v.empty()) {
            auto t = v.top();
            v.pop();
            ns.insert(t);
        }
    }

    // std::cout << ans << " ";
    cnt = 0;
    // std::cout << ns.size() << "\n";
    for (auto it = ns.rbegin(); it != ns.rend() && cnt < K - M; it++, cnt++) {
        // std::cout << *it << "\n";
        ans += *it;
    }
    std::cout << ans << "\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
