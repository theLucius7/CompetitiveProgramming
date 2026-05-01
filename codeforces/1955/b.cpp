#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 c, d;
    std::cin >> n >> c >> d;

    std::vector<i64> a(n * n);
    for (int i = 0; i < n * n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<i64> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        b.push_back(b[i - 1] + c); 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            b.push_back(b[i] + j * d);
        }
    }

    std::sort(b.begin(), b.end());

    for (int i = 0; i < n * n; i++) {
        if (a[i] != b[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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