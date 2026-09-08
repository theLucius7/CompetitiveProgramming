#include <bits/stdc++.h>
#define int long long
using namespace std;
int n ,m ,k;
int p[100009];

bool ch(int x)
{
    vector<int> q(n+1);
    for(int i = 1 ; i<= x ; i++)
    {
        if(p[i] % m == 0)
        {
            q[p[i]/m-1]++;
        }
        else q[p[i]/m]++;
    }
    int ma = 0;
    for(int i = 0 ; i<n ; i++)
    {
        ma = max(ma,q[i]);
    }
    if(ma + k >=m) return true;
    else return false;
}
void solve() {
	cin >> n >> m >> k;
    for(int i = 1 ; i<= n*m ; i++)
    {
        cin >> p[i];
    }
    int l = m,r = m*n,mid;
    int ans;
    while(l <= r)
    {
        mid = (l + r) /2;
        if(ch(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int T = 1;
	std::cin >> T;
	while (T -- ) {
		solve();
	}
	
	return 0;
}