#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque <array <int, 2>> q;
    while (n -- ) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, c;
            cin >> x >> c;
            q.push_back ({c, x});
        } else {
            int c;
            cin >> c;

            LL ans = 0;
            while (q[0][0] < c) {
                c -= q[0][0];
                ans += 1LL * q[0][0] * q[0][1];
                q.pop_front ();
            }
            if (c) {
                q[0][0] -= c;
                ans += 1LL * c * q[0][1];
            }
            cout << ans << "\n";
        }
    }


    return 0;
}