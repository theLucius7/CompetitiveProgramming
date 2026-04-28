#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> g[N]; // g[u]: u房间的门，记录目标房间编号
map<int, int> door_map[N]; // door_map[u][v]: 房间u到v的门编号（从1开始）

set<pair<int,int>> visited_corridors[N]; // 每个房间经过的走廊集合

int n;

pair<int,int> canonical(int u, int v) {
    if (u > v) swap(u,v);
    return {u,v};
}

int next_door(int u, int in_door) {
    int d = g[u].size();
    if (in_door == 0) return 1; // 初始状态，走1号门
    return in_door % d + 1; // 依规则选择下一扇门
}

void simulate(int start) {
    set<pair<int,int>> corridor_set;
    int u = start;
    int in_door = 0; // 初始入门编号为0

    map<pair<int,int>, int> vis_order; // 用于找环，记录状态出现的时间
    vector<pair<int,int>> path;

    int step = 0;

    while (true) {
        pair<int,int> state = {u, in_door};
        if (vis_order.count(state)) {
            // 找到环
            int loop_start = vis_order[state];
            for (int i = loop_start; i < path.size(); ++i) {
                int x = path[i].first;
                int in_d = path[i].second;
                int out_d = next_door(x, in_d);
                int y = g[x][out_d-1];
                corridor_set.insert(canonical(x,y));
            }
            break;
        }
        vis_order[state] = step++;
        path.push_back(state);

        // 走一条走廊
        int out_door = next_door(u, in_door);
        int v = g[u][out_door-1];
        corridor_set.insert(canonical(u, v));

        // 转移
        int next_in_door = door_map[v][u];
        u = v;
        in_door = next_in_door;
    }

    visited_corridors[start] = corridor_set;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int u = 1; u <= n; ++u) {
        int d;
        cin >> d;
        g[u].resize(d);
        for (int i = 0; i < d; ++i) {
            int v;
            cin >> v;
            g[u][i] = v;
            door_map[u][v] = i+1; // 记录u到v是第i+1扇门
        }
    }

    for (int i = 1; i <= n; ++i) {
        simulate(i);
    }

    for (int i = 1; i <= n; ++i) {
        cout << visited_corridors[i].size() << "\n";
    }

    return 0;
}
