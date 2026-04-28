#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::unordered_map<std::string, bool> umap1, umap2;
	std::vector<std::string> l1, l2;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;

		if (!umap1[s]) {
			umap1[s] = true;
			l1.push_back(s);

		}
	}

	for (int i = 0; i < m; i++) {
		std::string s;
		std::cin >> s;

		if (!umap2[s]) {
			umap2[s] = true;
			l2.push_back(s);
		}
	}

	std::unordered_map<std::string, bool> umap3;
	std::vector<std::string> s;
	for (int i = 0, j = 0; i < l1.size() || j < l2.size(); ) {
		if (i >= l1.size()) {
			if (!umap3[l2[j]]) {
				s.push_back(l2[j]);
				umap3[l2[j]] = true;
			}
			j++;
		} else if (j >= l2.size()) {
			if (!umap3[l1[i]]) {
				s.push_back(l1[i]);
				umap3[l1[i]] = true;
			}
			i++;
		} else if (i < j) {
			if (!umap3[l1[i]]) {
				s.push_back(l1[i]);
				umap3[l1[i]] = true;
			}
			i++;
		} else if (i > j) {
			if (!umap3[l2[j]]) {
				s.push_back(l2[j]);
				umap3[l2[j]] = true;
			}
			j++;
		} else {
			if (!umap3[l1[i]]) {
				s.push_back(l1[i]);
				umap3[l1[i]] = true;
			}
			if (!umap3[l2[j]]) {
				s.push_back(l2[j]);
				umap3[l2[j]] = true;
			}
			i++;
			j++;
		}
	}

	for (int i = 0; i < s.size(); i++) {
		std::cout << s[i] << "\n";
	}

	return 0;
}