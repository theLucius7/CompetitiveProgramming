#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5E5 + 10, MOD = 998244353;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int pow2[N];
    pow2[0] = 1;
    for(int i = 1; i <= N; ++i) {
        pow2[i] = (i64)pow2[i - 1] * 2 % MOD;
    }

    int T;
    std::cin >> T;

    while(T--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n + 1);
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            if(a[i] == -1) cnt++;
        }

        i64 sum = 0;
        if (a[1] != 0) { 
            if (a[1] == 1) {
                sum = (pow2[cnt] % MOD + sum) % MOD;
            } else if (a[1] == -1) {
                sum = (pow2[cnt - 1] % MOD + sum) % MOD;
            }
        }

        for (int i = 2; i <= n; ++i) {
            if (a[i - 1] == 1) continue;
            if (a[i] == 0) continue;
            int ans = 0;
            if (a[i - 1] == -1) ans++;
            if (a[i] == -1) ans++;
            sum = (pow2[cnt - ans] % MOD + sum) % MOD;
        }
        std::cout << (sum % MOD) << "\n";
    }

    return 0;
}
