#include <bits/stdc++.h>


using i64 = long long;

void solve() {
    int n;
    i64 c;
    std::cin >> n >> c;

    std::multiset<i64> st;
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;
        st.insert(x);
    }

    int coins = 0;
    i64 x = 1;

    while (!st.empty()) {
        auto it = st.upper_bound(c / x);
        if (it == st.begin()) {
            coins++;
            st.erase(st.begin());
        } else {
            --it;
            st.erase(it);
        }

        x *= 2;
    }

    std::cout << coins << '\n';
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