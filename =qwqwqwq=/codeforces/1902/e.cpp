#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1E6 + 10;

int tot = 1;
int trie[N][26];
int cnt[N];


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::string> s(n);
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		ans += s[i].size();

		int p = 1;
		for (auto c : s[i]) {
			int &q = trie[p][c - 'a'];
			if (!q) {
				q = ++tot;
			}
			p = q;
			cnt[p] += 1;
		}
	}

	ans *= 2 * n;
	for (int i = 0; i < n; i++) {
		std::reverse(s[i].begin(), s[i].end());

		int p = 1;
		for (auto c : s[i]) {
			int &q = trie[p][c - 'a'];
			if (!q) {
				break;
			}
			p = q;
			ans -= 2 * cnt[p];
		}
	}

	std::cout << ans << "\n";

	return 0;
}