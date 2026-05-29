#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

const int N = 1.5e5 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add (int a, int b, int c) {
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra () {
    memset (st, false, sizeof st);

    memset (dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue <PII, vector <PII>, greater <PII>> heap;
    heap.push ({0, 1});

    while (heap.size ()) {
        auto t = heap.top ();
        heap.pop ();

        int ver = t.y, distance = t.x;
        if (!st[ver]) {
            st[ver] = true;

            for (int i = h[ver]; ~i; i = ne[i]) {
                int j = e[i];
                if (dist[j] > dist[ver] ^ w[i]) {
                    dist[j] = dist[ver] ^ w[i];
                    heap.push ({dist[j], j});
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    }

    return dist[n];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    memset (h, -1, sizeof h);

    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;

        add (a, b, c);
    }

    


    cout << dijkstra();

    return 0;
}
