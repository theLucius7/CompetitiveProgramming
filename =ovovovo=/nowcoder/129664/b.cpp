#include <bits/stdc++.h>

using i64 = long long;
using real = long double;

struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    Nickyaso认为仅看完网课视频去考试十分不妥当，决定留些时间刷题。这样一来他的时间将会非常紧迫，他不得不重新规划他的网课学习方案。这一次Nickyaso将会列出 N 集视频，每条视频将会给出其时长(单位:分钟)和重要性，重要性以从小到大规定，1为最高等级，5为最低等级。理想情况下，Nickyaso的有效学习时间将是：所有网课视频的总时长 x 学习效率(100%)。


    不幸的是，Nickyaso由于巨大的焦虑和压力，学习效率会出现波动。具体来说，当他学习重要性为1、2等级的网课视频时，学习效率将会减少固定的10%，连续学习时效率将会连续降低，最低不会低于30%；当他学习重要性等级为3的网课视频时，效率不变；当他学习重要性等级为4、5的网课视频时，效率将会增加固定的5%，最高不会超过100%。


    除此之外，Nickyaso认为至少要学习 q 集网课视频才能顺利刷题练习。时间紧迫，Nickyaso拜托你帮他算出在这种情况下，他最长的有效学习时间是多少，并给出观看网课视频的顺序。

输入描述:
第一行输入一个正整数 N 表示视频数。

第二行至第 N+1 行输入三个非负整数 a , b , c ，分别代表该集视频的序号、时间(单位:分钟)和重要性。

第 N+2 行输入一个小数 m 和一个非负整数 q，代表Nickyaso最开始的学习效率和最少学习网课集数。

输出描述:
输出一共两行。

第一行输出Nickyaso最长的有效学习时长(单位:分钟) 。

第二行打印出Nickyaso的最长有效学习时长的观看网课序号的顺序。

示例1
输入
复制
6
1 28 1
2 38 1
3 27 3
4 35 4
5 60 5
6 45 2
0.8 5
输出
复制
193.80
4 5 3 6 2 1
备注:
对于全部数据，保证 0.3 ≤ m ≤ 1.0 , 1 ≤ N ≤ 20 , 1 ≤ c ≤ 5 , 1 ≤ b ≤ 300 , 1 ≤ q ≤ N，答案具有唯一性。

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<real> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }

    DSU dsu(n);
    
    std::vector<std::tuple<real, int, int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            edges.push_back({std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), i, j});
        }
    std::sort(edges.begin(), edges.end());
    
    real ans = 0;
    int cnt = 0;
    for (auto [w, u, v] : edges) {
        if (!dsu.same(u, v)) {
            dsu.merge(u, v);
            ans += w;

            cnt++;
            if (cnt == n - 1) {
                break;
            }
        }
    }
    
    std::cout << std::fixed << std::setprecision(9) << ans << "\n";
    return 0;
}
