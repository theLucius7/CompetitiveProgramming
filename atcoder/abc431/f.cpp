#include <bits/stdc++.h>
using i64 = long long;

static const int MOD = 998244353;

i64 modPow(i64 a, i64 e) {
    i64 r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    i64 D;
    if (!(std::cin >> N >> D)) return 0;
    std::vector<i64> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    // 预处理阶乘与逆元
    std::vector<i64> fact(N + 1, 1), invfact(N + 1, 1);
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    invfact[N] = modPow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) invfact[i - 1] = invfact[i] * i % MOD;

    // 两指针计算 c_i
    i64 ans = 1;
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j < N && a[j] <= a[i] + D) {
            j++;
        }
        int choices = j - i; // c_i - i
        if (choices <= 0) {
            std::cout << 0 << "\n";
            return 0;
        }
        ans = ans * choices % MOD;
    }

    // 多重集去重：除以各值频数的阶乘
    // 等价于乘 invfact[freq]
    for (int i = 0; i < N; ) {
        int k = i;
        while (k < N && a[k] == a[i]) k++;
        int freq = k - i;
        ans = ans * invfact[freq] % MOD;
        i = k;
    }

    std::cout << ans % MOD << "\n";
    return 0;
}
