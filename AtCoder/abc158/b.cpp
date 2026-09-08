#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, a, b;
    cin >> n >> a >> b;

    LL res = n / (a + b) * a + min (n % (a + b), a);

    cout << res << "\n";

    return 0;
}