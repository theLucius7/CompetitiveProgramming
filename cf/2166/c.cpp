#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 4E18 + 1;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int p = std::max_element(a.begin(), a.end()) - a.begin();
        
    std::vector<i64> st{inf};
    i64 ans = 0;
    for (int i = 0; i < n; i++){
        i64 x = a[(p + i) % n];
        while (st.back() < x){
            st.pop_back();
            ans += std::min(st.back(), x);
        }
        st.push_back(x);
    }
    
    while(st.size() > 2){
        st.pop_back();
        ans += st.back();
    }
    
    std::cout << ans << "\n";
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