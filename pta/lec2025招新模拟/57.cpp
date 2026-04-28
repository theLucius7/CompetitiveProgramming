#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b;
    std::cin >> a >> b;

    auto calc = [&](int x) -> int {
        std::string s = std::to_string(x);
        int cnt = 0;
        while (s.size() > 1) {
            int u = 1;
            for (int i = 0; i < s.size(); i++) {
                u *= s[i] - '0';
            }
            s = std::to_string(u);
            cnt++;
        }
        return cnt;
    };

    std::vector<int> ans;
    int max = 0;
    for (int i = a; i <= b; i++) {
        int c = calc(i);
        if (max < c) {
            ans.clear();
            ans.push_back(i);
            max = c;
        } else if (max == c) {
            ans.push_back(i);
        }
    }

    std::cout << max << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}