#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> a(n);
    vector <vector <int>> p(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        a[i] -- ;
        p[a[i]].push_back (i);
    }

    int m;
    cin >> m;

    while (m -- ) {
        int l, r, x;
        cin >> l >> r >> x;
        l -- , x -- ;
        cout << lower_bound (p[x].begin (), p[x].end (), r) - lower_bound (p[x].begin (), p[x].end (), l) << "\n";
    }

    return 0;
}