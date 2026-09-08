#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)) {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct Node {
	int to;
	int val;
	inline Node () {}
	inline Node (int x,int y) : to(x),val(y) {}
};
int n,ans=INT_MAX;
vector <Node> a[maxn];
inline void dfs(int x,int fa,int cost) {
	if (x==1 && fa) {
		ans=min(ans,cost);
		return ;
	}
	for (int i=0;i<2;i++) {
		int y=a[x][i].to;
		if (y==fa) continue;
		dfs(y,x,cost+a[x][i].val);
	}
}
int main() {
	n=read();
	for (int i=1;i<=n;i++) {
		int x=read(),y=read(),z=read();
		a[x].push_back(Node(y,0));
		a[y].push_back(Node(x,z));
	}
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}