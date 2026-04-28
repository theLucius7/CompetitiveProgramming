#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Fast modular exponentiation
int modpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = (1LL * r * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return r;
}

// Modular inverse
int modinv(int a) { return modpow(a, MOD - 2); }

struct Segment {
    int l, r, p, q;
    int prob;     // probability (p * q^{-1} % MOD)
    int one_minus; // (1 - prob + MOD) % MOD
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> seg_starts(m + 2), seg_ends(m + 2);
    vector<Segment> segs(n);

    for (int i = 0; i < n; ++i) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int invq = modinv(q);
        int prob = 1LL * p * invq % MOD;
        int one_minus = (1 - prob + MOD) % MOD;
        segs[i] = {l, r, p, q, prob, one_minus};
        seg_starts[l].push_back(i);
        seg_ends[r].push_back(i);
    }

    // Precompute prefix products of (1-prob) for "active" segments.
    vector<int> pre(m + 3, 1);
    vector<int> suf(m + 3, 1);
    // For each position, multiply in all starting and remove all ending segments.
    for (int i = 1; i <= m + 1; ++i) {
        pre[i] = pre[i - 1];
        for (int id : seg_starts[i]) {
            pre[i] = 1LL * pre[i] * segs[id].one_minus % MOD;
        }
    }
    for (int i = m + 1; i >= 1; --i) {
        suf[i] = suf[i + 1];
        for (int id : seg_ends[i - 1]) {
            suf[i] = 1LL * suf[i] * segs[id].one_minus % MOD;
        }
    }

    // dp[x]: number of ways to exactly cover [1, x-1]
    vector<int> dp(m + 3, 0);
    dp[1] = 1;
    for (int x = 1; x <= m; ++x) {
        if (dp[x] == 0) continue;
        // For all segments starting at x
        for (int id : seg_starts[x]) {
            int l = segs[id].l, r = segs[id].r;
            // The probability that all overlapping segments except id are absent
            // is pre[r] * modinv(pre[l]) (those started up to r, but not before l)
            int P = segs[id].prob;
            int mul = 1LL * pre[r] * modinv(pre[l]) % MOD;
            // Remove segment id's own one_minus factor: when calculating, we've included it in both pre[r] and pre[l]
            // but it is present only once. So we need to remove it (by multiplying modinv of one_minus)
            mul = 1LL * mul * modinv(segs[id].one_minus) % MOD;
            int val = 1LL * dp[x] * P % MOD * mul % MOD;
            dp[r + 1] = (dp[r + 1] + val) % MOD;
        }
    }
    cout << dp[m + 1] << '\n';
    return 0;
}
