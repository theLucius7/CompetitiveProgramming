#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::vector<int> cnt(10);
	for (int i = 0; i < S.size(); i++) {
		cnt[S[i] - '0']++;
	}

	std::cout << (cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3 ? "Yes" : "No") << "\n";

	return 0;
}