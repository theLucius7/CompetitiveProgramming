#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int bb,bt1,bt2,ba1,ba2;
    cin >> bb >> bt1 >> ba1 >> bt2 >> ba2;
    long double b,t1,a1,t2,a2;
    b = bb,t1 = bt1,a1 = ba1,t2 = bt2,a2 = ba2;
    long double sum1 = 0,sum2 = 0;
    if(t1 < t2){
        sum1 += min(a1/b,t2 - t1);
        a1 -= sum1 * b;
        if(a1 == 0){
            sum2 += a2 / b;
        }else{
            sum2 += a2/ (b / 2);
            sum1 += a1 / (b / 2);
            if(a2 > a1){
                sum2 -= (a2 - a1)/2/(b/2);
            }else{
                sum1 -= (a1 - a2)/2/(b/ 2);
            }
        }
    
        
    }else{
        sum2 += min(a2/b,t1 - t2) ;
        a2 -= sum2 * b;
        if(a2 == 0){
            sum1 += a1 / b;
        }else{
            sum1 += a1 / (b / 2);
            sum2 += a2/(b/2);
            if(a2 > a1){
                sum2 -= (a2 - a1)/2/(b/2);
            }else{
                sum1 -= (a1 - a2)/2/(b / 2);
            }
        }
        
    }
    cout << fixed << std::setprecision(12) << sum1 << " " << sum2 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
