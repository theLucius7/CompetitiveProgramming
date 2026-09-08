#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 1;

    vector <int> st(10000010);
    while (!st[n]) {
        st[n] = true;
        if (n % 2) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        cnt ++ ;
    }

    cout << cnt << "\n";

    return 0;
}