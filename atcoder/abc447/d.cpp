#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::vector<int> cnt(3);
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			cnt[0]++;
		} else if (S[i] == 'B' && cnt[0]) {
			cnt[0]--, cnt[1]++;
		} else if (S[i] == 'C' && cnt[1]) {
			cnt[1]--, cnt[2]++;
		}
	}

	std::cout << cnt[2] << "\n";


	return 0;
}