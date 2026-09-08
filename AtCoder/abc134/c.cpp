#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int d1 = 0, d2 = 0;

    vector <int> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        if (a[i] > d1) {
            d2 = d1;
            d1 = a[i];
        } else if (a[i] > d2) {
            d2 = a[i];
        }
    }

    for (int i = 0; i < n; i ++ ) {
        if (a[i] != d1) {
            cout << d1 << "\n";
        } else {
            cout << d2 << "\n";
        }
    }

    return 0;
}