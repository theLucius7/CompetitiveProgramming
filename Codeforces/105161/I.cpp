#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 2e5 + 10;
int a[N],c[N];
int n,m;
bool check(int x){
    multiset<pair<int,int>> s;
    for(int i = 1 ; i<= n ; i++){
        if(!s.empty() && c[i] != ((*s.begin()).second)){
            auto p = s.lower_bound(make_pair(x - a[i],-1));
            if(p == s.end()) return false;
            else s.erase(p);

        }else s.insert({a[i],c[i]});
    }
    return true;
}
void solve() {
    cin >> n;
    for(int i = 1 ; i<= n ; i++){
        cin >> a[i];
    }
    for(int i = 1 ; i<= n ; i++){
        cin >> c[i];
    }

    int lo = 2, hi = 2E8;
    while (lo < hi) {
        int m = (lo + hi + 1) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    std::cout << lo << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
