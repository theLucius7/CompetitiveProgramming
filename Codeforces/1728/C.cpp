#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#include<unordered_map>
#define IOS ios::sync_with_stdio(0);cin.tie(0)
#define FREOPEN freopen("in.in", "r", stdin);freopen("out.out", "w", stdout)
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define fo(i,a,n) for (int i=a;i<=n;i++)
#define ro(i,n,a) for (int i=n;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define si(a) (int)(a).size()
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
using namespace std;
template<typename T> using ve = vector<T>;
template<typename T> using vee = vector<ve<T>>;
typedef pair<int, int> PII;
typedef long long  ll;
//typedef __int128_t i128;
typedef double db;
const int N = 1e6+5, inf = 0x3f3f3f3f, mod = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f, Mod = 1e11 + 7;

inline void read(int& n){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch = getchar();}n = x * f;}

inline void print(int n){if(n<0){putchar('-');n*=-1;}if(n>9)print(n/10);putchar(n%10+'0');}

ll qmi(ll a, ll b){ll res=1%mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b) { return a * b / gcd(a, b);}

// ll fac[N+5], inv[N+5];
// void initC(){fac[0]=1,inv[0]=1;fo(i,1,N)fac[i]=fac[i-1]*i%mod,inv[i]=inv[i-1]*qmi(i,mod-2)%mod;}
// ll C(ll a, ll b){if(a<b)return 0;return fac[a]*inv[a-b]%mod*inv[b]%mod;}
// ll A(ll a, ll b){if(a<b)return 0;return fac[a]*inv[a-b]%mod;}

// ll primes[N],cnt,euler[N];bool st[N];
// void prime_euler(ll n){euler[1] = 1;fo(i,2,n){if(!st[i])primes[cnt ++ ] = i,euler[i] = i - 1;
// for(int j=0;primes[j]<=n/i;j++){int t=primes[j]*i;st[t]=true;if(i%primes[j]==0){
// euler[t]=euler[i]*primes[j];break;}euler[t]=euler[i]*(primes[j]-1);}}}

#define out(x...) cout << __LINE__ << ":" << #x << "->";err(x);
void err() {cout << endl;}
template<typename T,typename... U> void err(T arg, U &... args){cout<<arg<<" ";err(args...);}

// ll n, m, sum, k, T;
void solve()
{
	// cin >> n;
	// ve<ll> a(n + 1), b(n + 1), fa(n + 1), fb(n + 1);
	// fo(i, 1, n) cin >> a[i];
	// fo(i, 1, n) cin >> b[i];
	// sort(all(a));
	// sort(all(b));
	// ll ans = 0;
	// fo(i ,1, n) fa[i] = log10(a[i]) + 1, fb[i] = log10(b[i]) + 1;
	// fo(i, 1, n)
	// {
	// 	string t = to_string(b[i]);
	// 	string s = to_string(a[i]);
	// 	if(b[i] != a[i])
	// 	{
	// 		if(si(t) == si(s)) ans += 2;
	// 		if(si(t) > si(s)) ans += s
	// 	}
	// }
	int n;
	cin >> n;
	ve<int> a(n + 1), b(n + 1), c;
	multiset<int> s;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 1;i <= n;i ++) {
		cin >> b[i];
		if (s.count(b[i])) {
			s.erase(s.find(b[i]));
		}else {
			c.push_back(b[i]);
		}
	}
	a.clear();
	for (auto x : s) {
		a.push_back(x);
	}
	b = c;
	int res = 0;
	ve<int> cnt1(10), cnt2(10), cnt(10);
	for (auto &x : a) {
		if (x >= 10) {
			x = log10(x) + 1;
			cnt1[x] ++;
			res ++;
		}else {
			cnt1[x] ++;
		}
	}
	for (auto &x : b) {
		if (x >= 10) {
			x = log10(x) + 1;
			cnt2[x] ++;
			res ++;
		}else {
			cnt2[x] ++;
		}
	}

	for (int i = 1;i < 10;i ++) {
		cnt[i] = abs(cnt1[i] - cnt2[i]);
	}
	for (int i = 2;i < 10;i ++) {
		res += cnt[i];
	}
	cout << res << endl;

}
int main()
{
    IOS;
    //cout << fixed << setprecision(6);
//     #ifdef klxx
//     freopen("in.in", "r", stdin);
//     freopen("out.out", "w", stdout);
// #endif
int T;
           cin >> T; while(T--) 
solve();
return 0;
}