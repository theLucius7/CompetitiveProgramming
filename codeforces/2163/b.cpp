#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    std::vector<int> id(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        id[p[i]] = i;
    }

    std::string x;
    std::cin >> x;

    if (x.front() == '1' || x.back() == '1') {
        std::cout << -1 << "\n";
        return;
    }

    if (x.find('1') == std::string::npos) {
        std::cout << 0 << "\n";
        return;
    }


    std::string s(n, '0');
    auto apply = [&](int l, int r) {
        int lo = std::min(p[l], p[r]), hi = std::max(p[l], p[r]);
        for (int i = l + 1; i < r; i++) {
            if (lo < p[i] && p[i] < hi) {
                s[i] = '1';
            }
        }
    };

    int l = std::min(id[1], id[n]), r = std::max(id[1], id[n]);
    std::vector<std::pair<int,int>> steps;
    steps.emplace_back(l, r), steps.emplace_back(0, l), steps.emplace_back(0, r), steps.emplace_back(l,  n - 1), steps.emplace_back(r,  n - 1);

    
    std::vector<std::pair<int,int>> ans;
    for (auto [l, r] : steps) {
        if (l >= r) {
            continue;
        }
        ans.emplace_back(l, r);
        apply(l, r);
    }

    for (int i = 0; i < n; i++) {
        if (x[i] == '1' && s[i] == '0') {
            std::cout << -1 << "\n";
            return;
        }
    }

    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    std::cout << ans.size() << "\n";
    for (auto [l, r] : ans) {
        std::cout << (l + 1) << " " << (r + 1) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
