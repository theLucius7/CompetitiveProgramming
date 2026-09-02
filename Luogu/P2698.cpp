#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int N, D;
    std::cin >> N >> D;

    std::vector<std::array<int, 2>> A(N);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i][0] >> A[i][1];
    } 


    std::sort(A.begin(), A.end());

    std::vector<int> q;
    for (int i = n - 1; i >= 0; i--) {
        while (!q.empty() && A[i][1] >= A[i][q.back()]) {
            q.pop_back();
        }
        if (!q.empty()) {
            std::lower_bound(q.begin(), q.end(), A[i] + D);
        }
    }

	return 0;
}