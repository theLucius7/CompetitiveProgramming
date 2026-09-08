#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    int cnt= 0;
    for (int i = 0; i < m; i ++ ) {
        int a;
        cin >> a;

        if (a < x) {
            cnt ++ ;
        }
    }

    cout << min (cnt, m - cnt) << "\n";


    return 0;
}