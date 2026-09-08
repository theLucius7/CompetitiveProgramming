#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;

using namespace std;

void solve() {
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[((i - 1 + s.size()) % s.size()) % s.size()]) {
            std::cout << i << "\n";
            return;
        }
    }
    std::cout << "-1\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}