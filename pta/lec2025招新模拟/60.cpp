#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string A, B;
    std::getline(std::cin, A);
    std::getline(std::cin, B);

    std::unordered_map<char, bool> umap;
    for (int i = 0; i < B.size(); i++) {
        umap[B[i]] = true;
    }

    for (int i = 0; i < A.size(); i++) {
        if (!umap[A[i]]) {
            std::cout << A[i];
        }
    }

    return 0;
}