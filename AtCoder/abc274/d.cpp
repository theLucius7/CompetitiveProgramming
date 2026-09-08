#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, x, y;
int f[2 * N][2 * N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;

    memset (f, 0, sizeof f);
    f[N][N] = true;

    int x;
    cin >> x;

    f[x + N][0] = true;


    for (int i = 1; i < n; i ++ ) {
        int v;
        cin >> v;
        for (int j = 1000; j >= -1000; j -- ) {
            for (int k = 1000; k >= -1000; k -- ) {
                f[j + N][k + N] |= f[j + N - v][k + N];
                f[j + N][k + N] |= f[j + N][k + N - v];
                f[j + N][k + N] |= f[j + N + v][k + N];
                f[j + N][k + N] |= f[j + N][k + N + v];
            }
        }
    }

    if (f[x + N][y + N]) {
        cout << "Yes\n";
    } else {
        cout << "No\n"; 
    }

    return 0;
}