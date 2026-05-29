#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> a(N);
	std::map<int, bool> st;
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
		if (a[i] == -1) {
			continue;
		}

		if (st[a[i]] == false) {
			st[a[i]] = true;
		} else {
			std::cout << "No\n";
			return 0;
		}
	}

	std::cout << "Yes\n";
	for (int i = 0; i < N; i++) {
		if (a[i] == -1) {
			for (int j = 1; j <= N; j++) {
				if (!st[j]) {
					st[j] = true;
					std::cout << j << " \n"[i == N - 1];
					break;
				}
			}
		} else {
			std::cout << a[i] << " \n"[i == N - 1];
		}
	}

	return 0;
}