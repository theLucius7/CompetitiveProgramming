#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6;

LL calc (int a, int b) {
    return 1LL * a * a * a + 1LL * a * a * b + 1LL * a * b * b + 1LL * b * b * b;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n;
    cin >> n;

    LL res = 0x7f7f7f7f7f7f7f7f;
    for (int i = 0; i <= N; i ++ ) {
        int l = 0, r = N;
        while (l < r) {
            int mid = l + r >> 1;
            if (calc (i, mid) >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        res = min (res, calc (i, l));
    }

    cout << res << "\n";

    return 0;
}