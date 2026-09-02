#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

#define int long long


signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;	
	std::cin >> N;

	if (N % 2 == 0) {
		for (int i = 0; i < N; i++) {
			if (i == (N / 2) || i == (N / 2 - 1)) {
				std::cout << "=";
			} else {
				std::cout << "-";
			}
		}	
	} else {
		for (int i = 0; i < N; i++) {
			if (i == N / 2) {
				std::cout << "=";
			} else {
				std::cout << "-";
			}
		}
	}

	std::cout << "\n";


	return 0;
}