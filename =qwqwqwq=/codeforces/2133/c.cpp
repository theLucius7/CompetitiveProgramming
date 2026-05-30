#include <bits/stdc++.h>

using i64 = long long;

i64 ask(int x, const std::vector<int>& S) {
    std::cout << "? " << x << " " << (int)S.size() << " ";
    for (int v : S) std::cout << v << " ";
    flushln();
    i64 ans;
    if (!(std::cin >> ans)) std::exit(0); // 必须立即退出
    if (ans == -1) std::exit(0);          // 交互失败必须退出
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    if (!(std::cin >> T)) return 0;
    while (T--) {
        int n;
        std::cin >> n;

        // 1) 计算每个点的全局最长路长度 len[x]（S=全体）
        std::vector<int> all(n);
        std::iota(all.begin(), all.end(), 1);

        std::vector<int> len(n + 1, 1);
        for (int x = 1; x <= n; ++x) {
            len[x] = (int)ask(x, all); // n 次查询
        }

        // 找到最长路径起点 s 以及长度 L
        int s = 1, L = len[1];
        for (int i = 2; i <= n; ++i) {
            if (len[i] > L) { L = len[i]; s = i; }
        }

        // 2) 按长度分组
        std::vector<std::vector<int>> bylen(L + 1);
        for (int v = 1; v <= n; ++v) {
            if (len[v] >= 1 && len[v] <= L) bylen[len[v]].push_back(v);
        }

        std::vector<char> used(n + 1, 0);
        std::vector<int> path;
        path.reserve(L);

        int cur = s;
        used[cur] = 1;
        path.push_back(cur);

        // 逐步找下一跳：need = L-1, L-2, ..., 1
        for (int need = L - 1; need >= 1; --need) {
            // 候选集合 C：所有 len[v] == need 且未使用
            std::vector<int> C;
            C.reserve(bylen[need].size());
            for (int v : bylen[need]) if (!used[v]) C.push_back(v);

            // 这里按题意，必须存在至少一个下一跳
            // 用二分法在 C 中找一个使得 cur -> v 的点
            while ((int)C.size() > 1) {
                int mid = (int)C.size() / 2;
                std::vector<int> H(C.begin(), C.begin() + mid);
                std::vector<int> S = {cur};
                S.insert(S.end(), H.begin(), H.end());

                i64 r = ask(cur, S); // 如果答案为 2，下一跳在 H，否则在右半
                if (r == 2) {
                    C.assign(H.begin(), H.end());
                } else {
                    C.erase(C.begin(), C.begin() + mid);
                }
            }

            int nextv = C.front();
            path.push_back(nextv);
            used[nextv] = 1;
            cur = nextv;
        }

        // 输出最终答案（只输出一次）
        std::cout << "! " << (int)path.size() << " ";
        for (int v : path) std::cout << v << " ";
        std::cout << '\n'; std::cout.flush();
    }
    return 0;
}
