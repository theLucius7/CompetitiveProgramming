#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, K;
	std::cin >> N >> K;

	std::string S;
	std::cin >> S;

	std::map<std::string, int> map;
	for (int i = 0; i < N - K + 1; i++) {
		map[S.substr(i, K)]++;
	}

	std::vector<std::pair<int, std::string>> cnt;
	for (auto [s, k] : map) {
		cnt.emplace_back(k, s);
	}
	std::sort(cnt.begin(), cnt.end(), [&](std::pair<int, std::string> A, std::pair<int, std::string> B) {
		if (A.first != B.first) {
			return A.first > B.first;
		}
		return A.second < B.second;
	});

	int max = cnt[0].first;
	std::cout << max << "\n";

	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i].first == max) {
			std::cout << cnt[i].second << " ";
		}
	}

	return 0;
}

// 0 1 2 3 ... N - 2  N - 1
// 0 1 2 3 ... N - 2  N - 1

// i i + K - 1 < N // i < N - K + 1