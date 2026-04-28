#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int P, Q, X, Y;
    std::cin >> P >> Q >> X >> Y;

    std::cout << (P <= X && X < P + 100 && Q <= Y && Y < Q + 100 ? "Yes" : "No") << "\n";


	return 0;
}