#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using i64 = long long;

void solve() {
    i64 n;
    cin >> n;
    if (n & 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << n / 2 << " " << n / 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}