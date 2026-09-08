#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
#define i128 __int128 
using namespace std;
const int N = 2007, M = N * 4;
int n, q, a[N], b[N], c[N], d[N], e[N];
int cnt[N][N], pre[N][N];
int ns[N][N];
bool vis[N][N];
int mp[N][N], idt;
#define bs bitset < M > 
bs f[M];
int v[M], X[M], Y[M];

bool rev = false;
void insert(bs a, int w) {
	R(i, idt, 1) if(a[i]) {
		if(!f[i][i]) f[i] = a, v[i] = w;
		a ^= f[i], w ^= v[i];
	}
	if(w) rev = true;
} 
int main() {
//	freopen("thewitness.in", "r", stdin);
//	freopen("thewitness.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> q;
	L(i, 1, q) {
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
		--a[i], --c[i]; 
		if(e[i] == 0) continue;
		for(int u : {a[i], b[i]}) 
			for(int v : {c[i], d[i]}) 
				cnt[u][v] += (u == b[i]) ^ (v == d[i]) ? -1 : 1, vis[u][v] = true;
	}
	R(i, n, 1) {
		R(j, n, 1) {
			cnt[i][j] += cnt[i + 1][j];
		}
	}
	R(i, n, 1) {
		R(j, n, 1) {
			cnt[i][j] += cnt[i][j + 1];
		}
	}
	L(i, 1, n) L(j, 1, n) cnt[i][j] = cnt[i][j] ? 1 : 0, pre[i][j] = cnt[i][j];
	L(i, 1, n) L(j, 1, n) pre[i][j] += pre[i - 1][j];
	L(i, 1, n) L(j, 1, n) pre[i][j] += pre[i][j - 1];
//	L(i, 1, n) L(j, 1, n) {
//		cout << cnt[i][j] << " \n"[j == n];
//	}
	
	L(i, 1, q) {
		if(e[i] == 0) {
			int s = 0;
			for(int u : {a[i], b[i]}) 
				for(int v : {c[i], d[i]}) {
					s += pre[u][v] * ((u == b[i]) ^ (v == d[i]) ? -1 : 1);
				}
			if(s == (b[i] - a[i]) * (d[i] - c[i])) {
				cout << "No\n";
				return 0;
			}
		}
	}
	
	L(i, 0, n) L(j, 0, n) {
		if(vis[i][j]) {
			mp[i][j] = ++idt;
			X[idt] = i, Y[idt] = j;
		}
	}
	
	L(i, 1, q) {
		if(e[i]) {
			int op = e[i] == 1 ? 0 : 1;
			bs o;
			for(int u : {a[i], b[i]}) 
				for(int v : {c[i], d[i]}) 
					o.set(mp[u][v]);
			insert(o, op);
		}
	}
	
	L(i, 1, idt) 
		if(f[i][i]) {
			L(j, 1, i - 1) if(f[i][j]) 
				v[i] ^= v[j];
			ns[X[i]][Y[i]] = v[i];
		}
	
	R(i, n, 1) 
		R(j, n, 1) 
			ns[i][j] ^= ns[i - 1][j];
	R(i, n, 1) 
		R(j, n, 1) 
			ns[i][j] ^= ns[i][j - 1];
	
	if(rev) {
		cout << "No\n";
		return 0;
	}
	
	cout << "Yes\n";
	L(i, 1, n) {
		L(j, 1, n) {
			if(cnt[i][j]) {
				cout << (ns[i][j] ? 2 : 1) << ' ';
			} else {
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
} 