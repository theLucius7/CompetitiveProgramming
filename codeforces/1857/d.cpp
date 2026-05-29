#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> c(n);
    int max = -2E9 - 1;
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
        if (c[i] > max) {
            ans.clear();
            max = c[i];
            ans.push_back(i + 1);
        } else if (c[i] == max) {
            ans.push_back(i + 1);
        }
    }

    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
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