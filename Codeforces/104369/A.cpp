#include <bits/stdc++.h>

using namespace std;

void solve() {
    int y, n;
    cin >> y >> n;
    vector<int> x(n);
    map<int, int> mp;
    for (int i = 0; i < n; i ++ ) {
        cin >> x[i];
        mp[x[i]] = 1;
    }
    int z;
    cin >> z;
    int sum = 0;
    for (int i = y; i <= 9999; i ++ ) {
        if (!mp.count(i)) {
            sum ++ ;
        }
        if (z == i) {
            break;
        }
    }
    cout << sum << endl;
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