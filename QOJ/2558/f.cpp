#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Event {
    // time: 发生的整数秒；type=2 表示“相向追击”，type=3 表示“追静止点”
    long long time;
    int type;
    int i, j; // type=2 用到 (i -> j)，type=3 仅 i 用到，j=-1
    bool operator<(const Event& other) const {
        if (time != other.time) return time > other.time;       // 最小堆
        return type > other.type; // 同时刻时先处理 type=2（无所谓，稳妥一些）
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        --t[i];
    }

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 用“坐标 * 2”的技巧，把速度 0.5 统一成 1，全部用整数算
    vector<long long> A2(n);
    for (int i = 0; i < n; i++) A2[i] = 2LL * a[i];

    // 固定方向：目标在右 -> +1；目标在左 -> -1（题目保证坐标互异）
    vector<int> dir(n);
    for (int i = 0; i < n; i++) dir[i] = (A2[t[i]] > A2[i]) ? +1 : -1;

    // 反向边，用于“某个目标停下后，其所有指向它的人切换为追静止点”
    vector<vector<int>> rev(n);
    for (int i = 0; i < n; i++) rev[t[i]].push_back(i);

    vector<char> stopped(n, 0);
    vector<long long> ans(n, -1);          // 停止时间（秒，整数）
    vector<long long> stopPos2(n, 0);      // 停止时的 2x 坐标

    priority_queue<Event> pq;

    // 初始把所有“相向追击”的边放进事件堆
    // 在 2x 坐标下相对速度是 2，因此相遇时刻 time = |A2[j]-A2[i]| / 2（仍是整数）
    for (int i = 0; i < n; i++) {
        int j = t[i];
        if (dir[i] == -dir[j]) {
            long long time = llabs(A2[j] - A2[i]) / 2;
            pq.push({time, 2, i, j});
        }
    }

    auto activate_children = [&](int u, long long curT) {
        long long P2 = stopPos2[u];                // u 停止位置（2x 坐标）
        for (int k : rev[u]) if (!stopped[k]) {
            long long posk2 = A2[k] + 1LL * dir[k] * curT; // k 在 curT 时刻的位置（2x）
            long long Tk = curT + llabs(P2 - posk2);       // 追静止点：额外时间 = 距离 / 1
            pq.push({Tk, 3, k, -1});
        }
    };

    int left = n;
    while (!pq.empty() && left) {
        auto e = pq.top(); pq.pop();
        if (e.type == 2) { // 相向追击 i -> j
            int i = e.i, j = e.j;
            if (stopped[i]) continue;
            // 如果 j 在更早的时刻就已经停了，则这条相向事件失效（真实会在 type=3 中被处理）
            if (stopped[j] && ans[j] < e.time) continue;

            // 有效：i 在 e.time 停止；停止位置=起点 + dir*时间（2x 坐标下速度是 1）
            stopped[i] = 1; ans[i] = e.time; stopPos2[i] = A2[i] + 1LL * dir[i] * e.time; --left;

            // 如果是 2-环（j 的目标就是 i），则 j 同时也在这一刻停
            if (!stopped[j] && t[j] == i) {
                stopped[j] = 1; ans[j] = e.time; stopPos2[j] = A2[j] + 1LL * dir[j] * e.time; --left;
                activate_children(j, e.time); // 先激活 j 的粉丝
            }
            activate_children(i, e.time); // 再激活 i 的粉丝
        } else { // type=3：追静止点 i -> (已停目标)
            int i = e.i;
            if (stopped[i]) continue;
            stopped[i] = 1; ans[i] = e.time;
            stopPos2[i] = stopPos2[t[i]]; // i 停在目标的停止点
            --left;
            activate_children(i, e.time);
        }
    }

    // 输出
    for (int i = 0; i < n; i++) {
        // 题面保证“总能在有限时间停下，且为整数秒”
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
