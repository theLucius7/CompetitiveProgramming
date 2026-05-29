#include <bits/stdc++.h>

using i64 = long long;

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    int X;
    std::string Y;
    std::cin >> X >> Y;
    X--;

    if (S[X] == Y) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}