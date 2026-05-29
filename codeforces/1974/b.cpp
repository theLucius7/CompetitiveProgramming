#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string t = s, r;
    std::sort(t.begin(), t.end());

    r.push_back(t[0]);
    for (int i = 1; i < n; i++) {
        if (t[i] != t[i - 1]) {
            r.push_back(t[i]);
        }
    }

    std::unordered_map<char, char> umap; 
    for (int i = 0; i < r.size(); i++) {
        umap[r[i]] = r[r.size() - 1 - i];
    }

    for (int i = 0; i < s.size(); i++) {
        std::cout << umap[s[i]];
    }
    std::cout << "\n";
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