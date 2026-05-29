#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] %= M;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i] %= M;
    }

    std::multiset<int> set(A.begin(), A.end());

    std::vector<int> ans;
        for (int i = 0; i < N; i++) {
            int x = (M - (B[i] % M)) % M;

            auto it = set.lower_bound(x);
            if (it == set.end()) {
                it = set.begin(); 
            }
            
            int a = *it;
            ans.push_back((a + B[i]) % M);
            set.erase(it);
        }

    std::cout << std::accumulate(ans.begin(), ans.end(), 0LL) << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while(t--) {
        solve();
    }
   
	return 0;
}