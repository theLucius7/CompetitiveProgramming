#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::vector<std::string> v;
    while (std::cin >> s) {
        if (s == "#") {
            break;
        }
        v.push_back(s);
    }

    std::stable_sort(v.begin(), v.end(), [](std::string a, std::string b) {
        return a.size() < b.size();
    });

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    return 0;
}
