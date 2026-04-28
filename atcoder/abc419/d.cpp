#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> diff(N + 2);
    for (int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;

        diff[L]++;
        diff[R + 1]--;
    }

    std::string ans;
    int x;
    for (int i = 0; i < N; i++) {
        x += diff[i + 1];
        if (x & 1) {
            ans += T[i];
        } else {
            ans += S[i];
        }
    }

    std::cout << ans << "\n";


	return 0;
}