#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 1);

    do {
        for (int i = 0; i < p.size(); i++) {
            std::cout << p[i];
        }
        std::cout << "\n";
    } while (std::next_permutation(p.begin(), p.end()));

    return 0;
}
