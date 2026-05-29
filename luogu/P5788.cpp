#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> f(n);

    std::vector<int> stk;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }

        if (stk.empty()) {
            f[i] = 0;
        } else {
            f[i] = stk.back() + 1;
        }

        stk.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        std::cout << f[i] << " \n"[i == n - 1];
    }

	return 0;
}