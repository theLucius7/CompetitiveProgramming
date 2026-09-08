#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;
    
    n %= P;
    if (n < 0) {
        n += P;
    }
    cout << n << "\n";
    
    return 0;
}
