#include <bits/stdc++.h>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char c;
    std::cin >> c;

    std::cout << "  " << c << "\n";
    std::cout << " ";
    for (int i = 0; i < 3; i++) {
        std::cout << c;
    }
    std::cout << "\n";
    for (int i = 0; i < 5; i++) {
        std::cout << c;
    }
    std::cout << "\n";


    return 0;
}