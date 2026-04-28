#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

    i64 Rmin = LLONG_MAX, Rmax = LLONG_MIN;
    i64 Cmin = LLONG_MAX, Cmax = LLONG_MIN;

    for (int i = 0; i < N; i++) {
    	i64 R, C;
    	std::cin >> R >> C;

    	Rmin = std::min(Rmin, R);
        Rmax = std::max(Rmax, R);
        Cmin = std::min(Cmin, C);
        Cmax = std::max(Cmax, C);
    }

    std::cout << std::max((Rmax - Rmin + 1) / 2, (Cmax - Cmin + 1) / 2) << "\n";

	return 0;
}