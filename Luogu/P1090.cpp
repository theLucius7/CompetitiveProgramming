#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
    std::cin >> n;

    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;
        pq.push(a);
    }

    i64 ans = 0;
    while (pq.size() != 1) {
        i64 a = pq.top();
        pq.pop();
        i64 b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a + b);
    }
    std::cout << ans << "\n";

	return 0;
}