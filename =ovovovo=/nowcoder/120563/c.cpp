#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string S;
	std::cin >> S;

	std::string a;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != ((i % 2) ? '1' : '0')) {
			a.push_back(S[i]);
		}
	}

	std::vector<int> cnt(2);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1') {
			if (cnt[0]) {
				cnt[0]--;
				cnt[1]++;
			} else {
				cnt[1]++;
			}
		} else {
			if (cnt[1]) {
				cnt[1]--;
				cnt[0]++;
			} else {
				cnt[0]++;
			}
		}
	}

	int ans = cnt[0] + cnt[1];

	// std::cout << a << "\n";
	a.clear();

	for (int i = 0; i < S.size(); i++) {
		if (S[i] != ((i % 2) ? '0' : '1')) {
			a.push_back(S[i]);
		}
	}

	cnt[0] = 0, cnt[1] = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1') {
			if (cnt[0]) {
				cnt[0]--;
				cnt[1]++;
			} else {
				cnt[1]++;
			}
		} else {
			if (cnt[1]) {
				cnt[1]--;
				cnt[0]++;
			} else {
				cnt[0]++;
			}
		}
	}

	ans = std::min(ans, cnt[0] + cnt[1]);

	std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}