#include <bits/stdc++.h>
#define endl '\n'
// #define int long long
using i64 = long long;
using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;

int fac[N], infac[N];

int power(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = 1ll * res * a % mod;
        }
        a = 1ll * a * a % mod;
        k >>= 1;
    }
    return res;
}

void init() {
    fac[0] = infac[0] = 1;
    for (int i = 1; i < N; i ++ ) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        infac[i] = 1ll * infac[i - 1] * power(i, mod - 2) % mod;
    }
}

int C(int a, int b) {
    return 1ll * fac[a] * infac[b] % mod * infac[a - b] % mod;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = " " + s;
    vector<int> dp(n + 1);
    int cnt = 0;
    for (int i = 1, j = 1; i <= n; i ++ ) {
        if (s[i] == '1') {
            cnt ++ ;
            if (cnt == k) {
                if (i == 1) {
                    dp[i] = 1;
                } else {
                    dp[i] = (C(i - j, k - 1) + C(i - j, k)) % mod;
                }
            } else if (cnt > k) { 
                while (cnt > k) {
                    cnt -= s[j] == '1';
                    j ++ ;
                }
                dp[i] = (dp[i - 1] + C(i - j, k)) % mod;
            } else {
                dp[i] = 0;
            }
        } else {
            if (cnt == k) {
                dp[i] = (dp[i - 1] + C(i - j, k - 1)) % mod;
            } else {
                dp[i] = 0;
            }
        }
        // cout << dp[i] << " \n"[i == n];
    }
    cout << dp[n] << endl;
    // printf("%d\n", dp[n]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    // scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}