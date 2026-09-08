#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    if (s == t) {
        std::cout << "same\n";
        return;
    }

    std::map<char, int> map;
    map['O'] = 0;
    map['B'] = 1;
    map['A'] = 2;
    map['F'] = 3;
    map['G'] = 4;
    map['K'] = 5;
    map['M'] = 6;

    if (s[0] != t[0]) {
        std::cout << (map[s[0]] < map[t[0]] ? "hotter" : "cooler") << "\n";
    } else {
        std::cout << (s[1] < t[1] ? "hotter" : "cooler") << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}