#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::string S;
	std::cin >> S;

	std::vector<std::pair<char, int>> v;
	int cnt = 0;
	for (int l = 0, r = 0; l < N; l = r) {
		while (r < N && S[r] == S[l]) {
			r++;
		}
		if (S[l] == '1') {
			cnt++;
		}
		if (cnt == K) {
			auto u = v.back();
			v.pop_back();
			v.emplace_back(S[l], r - l);
			v.push_back(u);
		} else {
			v.emplace_back(S[l], r - l);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second; j++) {
			std::cout << v[i].first;
		}
	}

	return 0;
}