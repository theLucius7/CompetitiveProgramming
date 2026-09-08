#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
    int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

const int MAXN = 1e5;
int n, v, cnt1, cnt2, pos1, pos2, ans, sum, pre[MAXN + 5];
struct Node {
    int p, id;
    
    inline friend bool operator<(Node x, Node y) {
        return x.p > y.p;//按价值从大到小排序 
    }
} t1[MAXN + 5], t2[MAXN + 5];

int main() {
    read(n), read(v);
    for (int t, p, i = 1; i <= n; ++i) {
        read(t), read(p);
        if (t == 1) {
            t1[++cnt1].p = p;
            t1[cnt1].id = i;
        } else {
            t2[++cnt2].p = p;
            t2[cnt2].id = i;
        }//根据体积分成两类 
    }
    sort(t1 + 1, t1 + cnt1 + 1), sort(t2 + 1, t2 + cnt2 + 1);
    for (int i = 1; i <= cnt2; ++i) pre[i] = pre[i - 1] + t2[i].p;
    //预处理出体积为 2 的物品价值的前缀和 
    for (int i = 0; i <= min(v, cnt1); ++i) {//选了 i 个体积为 1 的物品 
        sum += t1[i].p;//体积为 1 的物品价值和
        //体积为 2 的物品选了 min(cnt2, (v - i) / 2) 个 
        if (sum + pre[min(cnt2, (v - i) / 2)] > ans) {//如果更优 
            ans = sum + pre[min(cnt2, (v - i) / 2)];
            pos1 = i, pos2 = min(cnt2, (v - i) / 2);//记录该方案的位置 
        }
    }
    write(ans);
    putchar('\n');
    for (int i = 1; i <= pos1; ++i) {
        write(t1[i].id);
        putchar(' ');
    }
    for (int i = 1; i <= pos2; ++i) {
        write(t2[i].id);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}