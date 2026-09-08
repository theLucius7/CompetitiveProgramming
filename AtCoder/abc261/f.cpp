#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
const int N = 3e5+100;

int n;
int tr[N];
vector<int>v[N];

void add(int x,int c){
    for(int i = x;i <= n + 1;i+=i&(-i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for(int i = x;i;i -= i&(-i))
        res += tr[i];
    return res;
}


int main()
{
    cin >> n;
    vector<int>c(n),x(n);

    for(int i = n - 1; i >= 0; i --) cin>>c[i];
    for(int i = n - 1; i >= 0; i --)
    {
        cin>>x[i];
        ++ x[i]; 
    }
    for(int i = 0 ; i <= n; i ++)  v[c[i]].push_back(x[i]);
    LL res = 0;
    //我先不考虑 颜色 计算一遍答案，然后考虑 减去 不需要cost
    for(int i = 0; i < n; i ++)
    {
        int tot = sum(x[i] - 1);
        res += tot;
        add(x[i],1);
    }
    for(int i = 0 ; i < n; i ++)
        add(x[i],-1);
    
    
    for(int i = 1;i <= n; i ++)
    {
        int sz = v[i].size();
        for(int j = 0; j < sz; j ++)
        {
            int tot = sum(v[i][j]-1);
            res -= tot;
            add(v[i][j],1);
        }
        for(int j = 0; j < sz; j ++) add(v[i][j],-1);
    }
    cout<<res;
    return(0);
}