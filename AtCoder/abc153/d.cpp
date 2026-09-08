#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL x;
    cin >> x;

    cout << (1LL << (__lg(x) + 1)) - 1 << "\n";


    return 0;
}