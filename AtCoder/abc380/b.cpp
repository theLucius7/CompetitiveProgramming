#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::vector<int> A;
	for (int l = 1, r = 1; l < S.size(); r++, l = r) {
		while (r < S.size() && S[r] == '-') {
			r++;
		}
		A.push_back(r - l);
	}

	for (int i = 0; i < A.size(); i++) {
		std::cout << A[i] << " \n"[i == A.size() - 1];
	}

	return 0;
}