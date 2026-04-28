#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9 + 1;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    std::set<i64> s;
    s.insert(0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s.count(pre[i + 1])) {
            cnt++;
            s.clear();
            s.insert(pre[i + 1]);
        } else {
            s.insert(pre[i + 1]);
        }
    }

    std::cout << cnt << "\n";
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