#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        
        A[i].resize(K);
        for (int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
        std::sort(A[i].begin(), A[i].end());
    }

    real ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            i64 cnt = 0;
            for (int x = 0, l = 0, r = 0; x < A[i].size(); x++) {
                while (l < A[j].size() && A[j][l] < A[i][x]) {
                    l++;
                }
                while (r < A[j].size() && A[j][r] <= A[i][x]) {
                    r++;
                }
                cnt += r - l;
            }
            ans = std::max(ans, 1.L * cnt / A[i].size() / A[j].size());
        }

    }

    std::cout << std::fixed << std::setprecision(10) << ans << "\n";


	return 0;
}