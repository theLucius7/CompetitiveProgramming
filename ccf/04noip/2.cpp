#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
	
const int N = 1e5 + 10;

int n;
int cnt[N];
queue <LL> p, q;

void read(int &x){ 
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}

int main () {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	read (n);

	int maxn = 0;
	for (int i = 0; i < n; i ++ ) {
		int x;
		read (x);

		cnt[x] ++ ;
		maxn = max (maxn, x);
	}

	for (int i = 1; i <= maxn; i ++ ) {
		while (cnt[i] -- ) {
			p.push (i);
		}
	}

	LL res = 0;
	for (int i = 0; i < n - 1; i ++ ) {
		LL x1;
		if (!q.size () || p.size () && p.front () < q.front ()) {
			x1 = p.front ();
			p.pop ();
		} else {
			x1 = q.front ();
			q.pop ();
		}

		LL x2;
		if (!q.size () || p.size () && p.front () < q.front ()) {
			x2 = p.front ();
			p.pop ();
		} else {
			x2 = q.front ();
			q.pop ();
		}

		q.push (x1 + x2);
		res += x1 + x2;
	}

	cout << res << "\n";

	return 0;
}