#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> id;
    for (int i = 0; i < n; i++) {
        
        if (s[i] == '1') {
            id.push_back(i + 1);
        }
    }
    std::cout << id.size() << "\n";
    for (int i = 0; i < id.size(); i++) {
        std::cout << id[i] << " \n"[i == id.size() - 1];
    }
    if (id.size() == 0) {
        std::cout << "\n";
    }
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