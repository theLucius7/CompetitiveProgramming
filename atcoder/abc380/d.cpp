#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
    std::cin >> S;

    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        i64 K;
        std::cin >> K;
        K--;

        char c = S[K % S.size()];
        K /= S.size();

        if (__builtin_parityll(K)) {
            if (std::islower(c)) {
                c = std::toupper(c);
            } else {
                c = std::tolower(c);
            }
        }  

        std::cout << c << " \n"[i == Q - 1];
    }

	return 0;
}
