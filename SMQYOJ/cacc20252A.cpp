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
        a[i] = std::abs(a[i]);
    }

    std::sort(a.begin(), a.end());

    i64 ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && a[l] * 2 >= a[r]) {
            r++;
        }
        ans += r - l - 1;
    }
    std::cout << ans << "\n";

   
	


	return 0;
}