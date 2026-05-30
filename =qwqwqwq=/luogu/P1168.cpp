#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::priority_queue<int, std::vector<int>> L;
	std::priority_queue<int, std::vector<int>, std::greater<int>> R;
	for (int i = 0; i < N; i++) {
		int A;
		std::cin >> A;

		L.push(A);
		R.push(L.top());
		L.pop();

		if (R.size() > L.size()) {
			L.push(R.top());
			R.pop();
		}

		if ((i + 1) % 2 == 1) {
			if (L.size() == R.size()) {
				std::cout << 0.5 * (L.top() + R.top()) << "\n";
			} else {
				std::cout << L.top() << "\n";
			}
		}
	}

	return 0;
}