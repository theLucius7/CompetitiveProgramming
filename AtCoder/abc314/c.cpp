#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::string s;
	std::cin >> s;

	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
		c[i]--;
	}

	std::vector<int> id(m, -1);
	std::vector<int> ans(n, -1);
	for (int i = 0; i < n; i++) {
		if (id[c[i]] != -1) {
			ans[i] = id[c[i]];
		} 
		id[c[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			ans[i] = id[c[i]];
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << s[ans[i]];
	}

	return 0;
}