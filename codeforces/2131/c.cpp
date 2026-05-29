#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

    std::map<i64,int> mapS, mapT;
    auto key = [&](i64 x) {
        i64 r = ((x % k) + k) % k;
        return std::min(r, (k - r) % k);
    };

    for (int i = 0; i < n; i++) {
    	i64 x;
    	std::cin >> x;
    	mapS[key(x)]++;
    }
    for (int i = 0; i < n; i++) {
	    i64 x;
	    std::cin >> x;
	    mapT[key(x)]++;
	}
    std::cout << (mapS == mapT ? "YES\n" : "NO\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
    	solve();    
    }

    return 0;
}
