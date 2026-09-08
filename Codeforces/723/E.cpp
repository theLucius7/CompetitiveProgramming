#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

constexpr int N = 210, M = 5E4 + 10;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N];
bool used[M];

void add (int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs (int u) {
    for (int &i = h[u]; ~i; ) {
        if (used[i]) {
            i = ne[i];
            continue;
        }

        used[i] = true;
        used[i ^ 1] = true;

        int j = e[i];
        i = ne[i];

		if (u != 0 && j != 0) {
            cout << u << " " << j << "\n";
        }

        dfs (j);
    }
}

void solve () {
    cin >> n >> m;

    memset (h, -1, sizeof h);
    idx = 0;

    memset (d, 0, sizeof d);

    memset (used, 0, sizeof used);

    for (int i = 0; i < m; i ++ ) {
        int a, b;
        cin >> a >> b;
        add (a, b);
        add (b, a);
        d[a] ++ ;
        d[b] ++ ;
    }

    int cnt = 0;

    for (int i = 1; i <= n; i ++ ) {
        if (d[i] & 1) {
            add (0, i);
            add (i, 0);
            d[0] ++ ;
            d[i] ++ ;
        } else {
            cnt ++ ;
        }
    }

    cout << cnt << "\n";

    for (int i = 1; i <= n; i ++ ) {
        if (~h[i]) {
            dfs (i);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T -- ) {
        solve ();
    }

    return 0;
}