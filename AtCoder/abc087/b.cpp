#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int d;
    cin >> d;

    int res = 0;
    for (int i = 0; i <= a; i ++ ) {
        for (int j = 0; j <= b; j ++ ) {
            for (int k = 0; k <= c; k ++ ) {
                if (500 * i + 100 * j + 50 * k == d) {
                    res ++ ;
                }
            }
        }
    }

    cout << res << "\n";


    return 0;
}