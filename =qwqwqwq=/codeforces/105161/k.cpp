#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n + 1);
    int ma = 0;
    for(int i = 1 ; i<= n ; i++){
        cin >> s[i];
        ma = max(ma,s[i]);
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++){
        if(ma == s[i]) cnt++;
    }
    if(cnt % 2){
        cout << "Alice" << "\n";
    }else cout << "Bob" << "\n";
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