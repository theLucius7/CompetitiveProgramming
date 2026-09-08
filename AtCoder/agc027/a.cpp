#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }

    sort (a.begin (), a.end ());

    int cnt = 0;
    while (a[cnt] <= m && cnt < n - 1) {
        m -= a[cnt];
        cnt ++ ;
    }

    if (a[cnt] == m) cnt ++ ;

    cout << cnt << "\n";

    return 0;
}