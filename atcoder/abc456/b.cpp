#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int cnt = 0;
	std::vector A(3, std::vector<int>(6));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			std::cin >> A[i][j];
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				std::set<int> s;
				s.insert(A[0][i]);
				s.insert(A[1][j]);
				s.insert(A[2][k]);

				std::set<int> t;
				t.insert(4);
				t.insert(5);
				t.insert(6);
				if (s == t) {
					cnt++;
				}
			}
		}
	}

	std::cout << std::fixed << std::setprecision(9) << 1.L * cnt / (6 * 6 * 6) << "\n";

	return 0;
}