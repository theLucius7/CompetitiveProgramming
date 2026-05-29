#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
    std::cin >> n;

    std::vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + 1) * (j + 1) > n) {
                break;
            }
            pq.push(A[i] + B[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int t = pq.top();
        std::cout << t << " \n"[i == n - 1];
        pq.pop();
    }

	return 0;
}