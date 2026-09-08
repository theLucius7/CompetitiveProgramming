#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++ ) {
        cin >> b[i];
    }
    deque<int> dq;
    for (int i = 0; i < n; i ++ ) {
        dq.push_back(a[i]);
    }
    for (int i = 0; i < n; i ++ ) {
        while (dq.front() != b[i]) {
            cout << "1";
            dq.push_back(dq.front());
            dq.pop_front();
        }
        if (i > 0) {
            dq.pop_front();
            while (dq.back() != b[i - 1]) {
                cout << "2";
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << "1";
            dq.push_back(b[i]);
        }
    }
    cout << endl;
    // for (int i = 0; i < n; i ++ ) {
    //     cout << b[i] << " \n"[i == n - 1];
    // }
    // for (int i = 0; i < n; i ++ ) {
    //     cout << dq.front() << " \n"[i == n - 1];
    //     dq.pop_front();
    // }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T -- ) {
        solve();
    }
    
    return 0;
}