#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n + 1), pre(n + 1);
        pre[0] = 0;
        
        map<int, vector<int>> pos; // 记录每个前缀异或值出现的位置
        pos[0].push_back(0);
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] ^ a[i];
            pos[pre[i]].push_back(i);
        }
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            
            int S = pre[r] ^ pre[l - 1];
            
            if (S == 0) {
                // 总异或为0，一定可以分成2部分
                cout << "YES\n";
                continue;
            }
            
            // 需要分成3部分，每部分异或值为S
            // 找i: pre[i] = pre[r], l <= i <= r-2
            // 找j: pre[j] = pre[l-1], i < j <= r-1
            
            auto& vec1 = pos[pre[r]];
            auto& vec2 = pos[pre[l - 1]];
            
            // 找最小的i >= l 且 pre[i] = pre[r]
            auto it1 = lower_bound(vec1.begin(), vec1.end(), l);
            if (it1 == vec1.end() || *it1 > r - 2) {
                cout << "NO\n";
                continue;
            }
            int i = *it1;
            
            // 找最小的j > i 且 pre[j] = pre[l-1]
            auto it2 = upper_bound(vec2.begin(), vec2.end(), i);
            if (it2 == vec2.end() || *it2 > r - 1) {
                cout << "NO\n";
                continue;
            }
            
            cout << "YES\n";
        }
    }
    
    return 0;
}