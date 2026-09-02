#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;
	std::cin >> S;

	std::vector<int> cnt(26);
	for (int i = 0; i < S.size(); i++) {
		cnt[S[i] - 'a']++;
	}

	int max = *std::max_element(cnt.begin(), cnt.end());
	std::vector<bool> vis(26);
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == max) {
			vis[i] = true;
		}
	}

	for (int i = 0; i < S.size(); i++) {
		if (!vis[S[i] - 'a']) {
			std::cout << S[i];
		}
	}
	std::cout << "\n";

	return 0;
}