#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    while (n--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x;
            std::cin >> x;
            pq.push(x);
        } else if (op == 2) {
            std::cout << pq.top() << "\n";
        } else {
            pq.pop();
        }
    }

	return 0;
}