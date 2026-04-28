#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (__builtin_clz(a) > __builtin_clz(b)) {
        std::cout << -1 << "\n";
        return;
    }

    if (a == b) {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> ans;
    for (int i = 0; i < 31; i++) {
        if (((a >> i) & 1 ) ^ ((b >> i) & 1)) {
            ans.push_back(1 << i);
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