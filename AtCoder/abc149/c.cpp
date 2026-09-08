#include <bits/stdc++.h>

using namespace std;

bool is_prime (int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ ) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (!is_prime (n)) {
        n ++ ;
    }

    cout << n << "\n";


    return 0;
}