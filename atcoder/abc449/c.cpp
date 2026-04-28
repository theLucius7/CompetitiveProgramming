#include <bits/stdc++.h>

using i64 = long long;

using real = long double;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, L, R;
	std::cin >> N >> L >> R;

	std::string S;
	std::cin >> S;

	std::vector<std::vector<int>> id(26);
	for (int i = 0; i < N; i++) {
		id[S[i] - 'a'].push_back(i);
	}

	i64 ans = 0;
	for (int c = 0; c < 26; c++) {
		auto a = id[c];
		int n = a.size();
		for (int i = 0, l = 0, r = 0; i < n; i++) {
			while (l < n && a[l] - a[i] < L) {
				l++;
			}
			while (r < n && a[r] - a[i] <= R) {
				r++;
			}
			ans += r - l;
		}
	}
	std::cout << ans << "\n";

	return 0;
}