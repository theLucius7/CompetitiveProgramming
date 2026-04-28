#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int N;
	std::cin >> N;

	std::vector<int> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}

	std::sort(S.begin() + 1, S.end() - 1);
	
	int last = S[0], cnt = 0;

	for (int i = 1; i < N - 1; i++) {
		if (last * 2 >= S[N - 1]) {
			std::cout << cnt + 2 << "\n";
			return;
		}

		if (last * 2 >= S[i] && S[i] > last) {
			for (int j = N - 2; j >= i; j--) {
				if (last * 2 >= S[j] && S[j] > last) {
					i = j;
					last = S[i];
					cnt++;
					break;
				}
			}
		}
	}
	if (last * 2 >= S[N - 1]) {
		std::cout << cnt + 2 << "\n";
		return;
	}

	std::cout << "-1\n";

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while(T--) {
		solve();
	}

	return 0;
}