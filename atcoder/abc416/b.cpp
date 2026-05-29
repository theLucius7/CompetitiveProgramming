#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::string T;


	bool placed = false;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '#') {
            T += '#';
            placed = false;
        } else if (!placed) {
            T += 'o';
            placed = true;
        } else {
            T += '.'; 
        }
    }

    std::cout << T << "\n";

   
	return 0;
}