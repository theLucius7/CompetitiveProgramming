#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, X;
	std::cin >> N >> X;


	bool ok = false;
	for (int i = 0; i < N; i++) {
		int a;
		std::cin >> a;

		if (a == X) {
			std::cout << i << "\n";
			ok = true;
		}
	}

	if (!ok) {
		std::cout << "Not Found\n";
	}

	return 0;
}