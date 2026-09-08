#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K, m;
    cin >> n >> K >> m;

    vector <int> a(n + 1, K - m);
    for (int i = 0; i < m; i ++ ) {
        int x;
        cin >> x;
        a[x] ++ ;
    }

    for (int i = 1; i <= n; i ++ ) {
        if (a[i] > 0) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}