#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n * (n - 1) / 2);
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        std::cin >> a[i];
    }

    // if (n == 2) {
    //     std::cout << a[0] << "\n";
    //     return;
    // }


    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        // std::cout << ((n - 1) + (n - 1 - i)) * (i + 1) / 2 << " \n"[i == n - 1];
        std::cout << a[((n - 1) + (n - 1 - i)) * (i + 1) / 2 - 1] << " \n"[i == n - 1];
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