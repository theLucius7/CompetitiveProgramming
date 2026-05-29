#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	int cnt = 0;
	while(N--) {
		int A, B;
		std::cin >> A >> B;

		if (B > A) {
			cnt++;
		}
	}
	std::cout << cnt << "\n";

	return 0;
}