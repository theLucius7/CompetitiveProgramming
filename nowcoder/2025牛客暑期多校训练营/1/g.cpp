#include<bits/stdc++.h>

using i64 = long long;
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::string S;
    std::cin >> S;

    std::vector<int> P;
    while(q--) {
        std::string T;
        int a;
        std::cin >> T >> a;

        int u = 0;
        for (int i = 0; i < T.size(); i++) {
            if (T[i] == S[i + a - 1]) {
                u++;
            } else {
                if (u) {
                    P.push_back(u);
                }
                u = 0;
            }
        }

        if (u) {
            P.push_back(u);
        }
        u = 0;

        i64 ans = 0;
        for (auto x : P) {
            ans += (1LL * x * (x - 1) / 2 + x);
        }
        std::cout << ans << "\n";

        P.clear();
    }



    return 0;
}