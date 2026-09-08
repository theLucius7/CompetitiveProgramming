#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> a(n), b(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++ ) {
        cin >> b[i];
    }

    vector <int> c(n);
    iota (c.begin (), c.end (), 1);

    int cnt = 1;
    int cnt1, cnt2;
    do {
        if (a == c) cnt1 = cnt;
        if (b == c) cnt2 = cnt;
        cnt ++ ;
    } while (next_permutation (c.begin (), c.end ()));

    cout << abs (cnt1 - cnt2) << "\n";

    return 0;
}