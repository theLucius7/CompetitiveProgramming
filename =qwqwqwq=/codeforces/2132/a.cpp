#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    int m;
    std::cin >> m;

    std::string b, c;
    std::cin >> b >> c;

    std::string s, t;
    for (int i = 0; i < m; i++) {
        if (c[i] == 'D') {
            s += b[i];
        } else {
            t += b[i];
        }
    }

    std::reverse(t.begin(), t.end());
    std::cout << t << a << s << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}