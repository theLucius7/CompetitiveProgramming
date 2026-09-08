#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define pii pair<int,int>
#define mp make_pair

//char buf[1 << 20], *p1, *p2;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2)?EOF: *p1++)
template <typename T> inline void read(T &t) {
	int v = getchar();T f = 1;t = 0;
	while (!isdigit(v)) {if (v == '-')f = -1;v = getchar();}
	while (isdigit(v)) {t = t * 10 + v - 48;v = getchar();}
	t *= f;
}
template <typename T,typename... Args> inline void read(T &t,Args&... args) {
	read(t);read(args...);
}

const int N = 1e6 + 10;

ll a[N],tag[N],n,q;

struct node {
    int l,r;
    ll tag1,tag2,col,sam;
}tree[N<<2];

void pushup(int p) {
    tree[p].col = tree[p << 1].col;
    tree[p].sam = ((tree[p << 1].sam && tree[p << 1 | 1].sam )&& (tree[p << 1].col == tree[p << 1 | 1].col));
}

void build(int p,int l,int r) {
    tree[p].l = l,tree[p].r = r;
    if (l == r) {
        tree[p].col = 1;
        tree[p].sam = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid + 1,r);
    pushup(p);
}

void pushdown(int p) {
    if (tree[p].tag1) {
        tree[p << 1].tag1 += tree[p].tag1;
        tree[p << 1 | 1].tag1 += tree[p].tag1;
        tree[p].tag1 = 0;
    }
    if (tree[p].tag2) {
        tree[p << 1].col = tree[p << 1 | 1].col = tree[p].tag2;
        tree[p << 1].tag2 = tree[p << 1 | 1].tag2 = tree[p].tag2;
        tree[p << 1].sam = tree[p << 1 | 1].sam = 1;
        tree[p].tag2 = 0;
    }
}

void change(int p,int l,int r,int k) {
    if (tree[p].l >= l && tree[p].r <= r && tree[p].sam) {
        tree[p].tag1 += tag[tree[p].col];
        tree[p].col = k;
        tree[p].tag2 = k;
        tree[p].sam = 1;
        tree[p].tag1 -= tag[k];
        return ;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (l <= mid) change(p << 1,l,r,k);
    if (r > mid) change(p << 1 | 1,l,r,k);
    pushup(p);
}

ll query(int p,int x) {
    //printf("%lld %lld %lld %lld %lld\n",p,tree[p].l,tree[p].r,tree[p].tag2,tree[p].col);
    if (tree[p].l == tree[p].r) {
        return tree[p].tag1 + tag[tree[p].col];
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (x <= mid) return query(p << 1,x);
    else return query(p << 1 | 1,x);
}

signed main() {
    read(n,q);
    build(1,1,n);
    for (int i = 1;i <= q;++i) {
        char opt[10];scanf("%s ",opt);
        if (opt[0] == 'C') {
            int x,y,w;read(x,y,w);
            change(1,x,y,w);
        }
        if (opt[0] == 'A') {
            int x,k;read(x,k);
            tag[x] += k;
        }
        if (opt[0] == 'Q') {
            int x;read(x);
            printf("%lld\n",query(1,x));
        }
    }
	return 0;
}