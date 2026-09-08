#include <bits/stdc++.h>

using i64 = long long;

using namespace std;


void solve() {
    std::string s;
    std::cin >> s;

    if (s == "ikimasu") {
        std::cout << "itte\n";
        return;
    }

    if (s.size() >= 7 && s[s.size() - 7] == 's' && s[s.size() - 6] == 'h') {
        for (int i = 0; i < s.size() - 7; i++) {
            std::cout << s[i];
        }
        std::cout << "shite\n";
    } else if (s.size() >= 7 && s[s.size() - 7] == 'c' && s[s.size() - 6] == 'h') {
        for (int i = 0; i < s.size() - 7; i++) {
            std::cout << s[i];
        }
        std::cout << "tte\n";
    } else {
        if (s[s.size() - 6] == 'm' || s[s.size() - 6] == 'b' || s[s.size() - 6] == 'n') {
            for (int i = 0; i < s.size() - 6; i++) {
                std::cout << s[i];
            }
            std::cout << "nde\n";
        } else if (s[s.size() - 6] == 'g') {
            for (int i = 0; i < s.size() - 6; i++) {
                std::cout << s[i];
            }
            std::cout << "ide\n";
        } else if (s[s.size() - 6] == 'k') {
            for (int i = 0; i < s.size() - 6; i++) {
                std::cout << s[i];
            }
            std::cout << "ite\n";
        } else {
            for (int i = 0; i < s.size() - 6; i++) {
                std::cout << s[i];
            }
            std::cout << "tte\n";
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}