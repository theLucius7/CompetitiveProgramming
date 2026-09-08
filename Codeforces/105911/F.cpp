    #include <bits/stdc++.h>
     
    using i64 = long long;
    using namespace std;
     
    #define int long long
     
    void solve() {
        int n, k ;
        __float128 r0 ,c0, p ,l ,r;
        cin >> n >> k;
        long double dr0, dc0, dp, dl, dr;
        std::cin >> dr0 >> dc0 >> dp >> dl >> dr;
        r0 = dr0;
        c0 = dc0;
        p = dp;
        l = dl;
        r = dr;
        // cin >> r0 >> c0 >> p >> l >> r;
        vector<__float128> v(n + 1,0),c(n+1);
        for(int i = 0 ;i < k; i ++){
            int udp ;
            cin >> udp;

            long double d;
            std::cin >> d;
            v[udp] = d;
        }
        v[n] = l;
        c[0] = c0,v[0] = r0;
        for(int i = 1 ; i<= n ; i++){
            if(v[i] == 0.0){
                v[i] = l;
            }
            c[i] = p * (c[i-1] - v[i - 1]) +  v[i-1];
        }
       
        __float128 sum = 0.L ,ans = 0.L;
        for(int i = 1 ; i<= n ; i++){
            sum += c[i];
            ans += v[i];
           // cout << c[i] << " " << v[i] << "\n";
        }
        cout << fixed << setprecision(15) << (long double)(sum - ans) << "\n";
        
    }
     
    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
     
     
        int t = 1;
         std::cin >> t;
     
        while (t--) {
            solve();
        }
     
    }