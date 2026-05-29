#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> A(N), len(N);
    int maxLen = 0;
    for (int i = 0; i < N; i++) {
    	std::string s;
    	std::cin >> s;
    	A[i] = std::stoi(s);
    	len[i] = s.size();
    	maxLen = std::max(maxLen, len[i]);
    }

    std::vector<i64> pow10(maxLen + 1);
    pow10[0] = 1 % M;
    for (int d = 1; d <= maxLen; d++) {
        pow10[d] = pow10[d - 1] * 10 % M;
    }

    std::vector<std::unordered_map<int, i64>> cnt(maxLen + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= maxLen; j++) {
            int r = (i64)(A[i] % M) * pow10[j] % M;
            cnt[j][r] += 1;
        }
    }

    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        auto it = cnt[len[i]].find((M - (A[i] % M)) % M);
        if (it != cnt[len[i]].end()) {
            ans += it -> second;
        }
    }
    std::cout << ans << "\n";

	return 0;
}