#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<std::pair<int, int>> stk;
    std::vector<int> r(N);
    for (int i = N - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] > stk.back().first) {
            stk.pop_back();
        }

        if (stk.empty()) {
            r[i] = N;
        } else {
            r[i] = stk.back().second;
        }

        if (!stk.empty() && a[i] == stk.back().first) {
            stk.pop_back();
        }

        stk.emplace_back(a[i], i);
    }


    i64 ans = 0;
    for (int i = 0; i < N; i++) {
        ans += r[i] - i - 1;
    }
    std::cout << ans << "\n";

	return 0;
}